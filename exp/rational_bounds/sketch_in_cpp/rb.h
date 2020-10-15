#include <cstdint>
#include <limits>
#include <algorithm>
#include <array>
#include <vector>


using uint128_t = __uint128_t;	// this is non-standard

// The subset of rational numbers that fit uint32_ts.
struct r32 {
	uint32_t n;	// numenator
	uint32_t d;	// denominator
	bool p;	// is positive?
};

// Rational bounds structure. 
// It represents a continuous interval from lower bound to upper bound inclusive
struct rb32 {
	r32 lb;	// lower bound
	r32 ub;	// upper bound
};

// The subset of rational numbers that fit uint64_ts.
struct r64 {
	uint64_t n;	// numenator
	uint64_t d;	// denominator
	bool p;	// is positive?
};

bool operator<(const r32& l, const r32& r){
	if(!l.p && r.p) return true;
	if(l.p && !r.p) return false;
	if(!l.p && !r.p) return static_cast<uint64_t>(l.n) * r.d > static_cast<uint64_t>(r.n) * l.d;
	return static_cast<uint64_t>(l.n) * r.d < static_cast<uint64_t>(r.n) * l.d;
}

bool operator>(const r32& l, const r32& r){
	return r < l;
}

bool operator==(const r32& l, const r32& r){
	return !(l < r || r < l);
}

bool operator!=(const r32& l, const r32& r){
	return l < r || r < l;
}

bool operator<=(const r32& l, const r32& r){
	return l < r || l == r;
}

bool operator>=(const r32& l, const r32& r){
	return r < l || r == l;
}

r32 inverted_r32(r32 x) {
	return r32{x.n, x.d, !x.p};
}

bool operator<(const r64& l, const r64& r){
	if(!l.p && r.p) return true;
	if(l.p && !r.p) return false;
	if(!l.p && !r.p) return static_cast<uint128_t>(l.n) * r.d > static_cast<uint128_t>(r.n) * l.d;
	return static_cast<uint128_t>(l.n) * r.d < static_cast<uint128_t>(r.n) * l.d;
}

bool operator==(const r64& l, const r64& r){
	return !(l < r || r < l);
}

r64 inverted_r64(r64 x) {
	return r64{x.n, x.d, !x.p};
}

r64 upcast(r32 x) {
	return r64{x.n, x.d, x.p};
}

r32 downcast_to_lower_bound(r64 x) {
	if(x.n <= std::numeric_limits<uint32_t>::max() && x.d <= std::numeric_limits<uint32_t>::max())
		return r32{static_cast<uint32_t>(x.n), static_cast<uint32_t>(x.d), x.p};
	// We need to shift both N and D so they could fit uint32_t.
	// Unfortunatelly, C++ has no standard way of determining the last bit set so we could use it
	// to find a shift operand without the extra checks.
	// There is POSIX flsll() but it isn't C++ and there is good way to map fls, flsl, or flsll to uint64_t.
	// The alternative would be probably to use the native Intel TZCNT on N | D, or de Bruijn algorithm.
	// Anyway, at this point this would be an overoptimization.
	auto y = r64{x.n, x.d, x.p}; // to contain shifted x
	while(y.n > std::numeric_limits<uint32_t>::max() || y.d > std::numeric_limits<uint32_t>::max()){
		y.n >>= 1;
		y.d >>= 1;
	}

	// There is a number that is representative in R32, isn't greater than X, and that the difference between
	// X and this number is the least possible. The exact N and D of this number depends on the N/D proportion in the
	// original X, on the shared sign on the numbers, and even on the proportion of the part we cut when shifted.
	// The logic behind this becomes complicated.
	// It's simpler to put five hypotheses into test and find a number that fits the most.
	std::array<r64, 5> hypotheses{r64{y.n+1, y.d, y.p}, r64{y.n-1, y.d, y.p}, r64{y.n, y.d-1, y.p}, r64{y.n, y.d+1, y.p}, r64{y.n, y.d, y.p}};
	std::vector<r64> not_greater_than_x(hypotheses.size());
	auto last_copy = std::copy_if(hypotheses.begin(), hypotheses.end(), not_greater_than_x.begin(), [&x](const r64& z){return !(x < z);});
	auto best_hypothesis = *std::max_element(not_greater_than_x.begin(), last_copy);

	// It might now exceed the R32 due to +1s so it's best to double check.
	return downcast_to_lower_bound(best_hypothesis);
}

r32 downcast_to_upper_bound(r64 x) {
	return inverted_r32(downcast_to_lower_bound(inverted_r64(x)));
}

r64 non_negative_add(r32 a, r32 b) {
	return r64{static_cast<uint64_t>(a.n) * b.d + static_cast<uint64_t>(b.n) * a.d, static_cast<uint64_t>(b.d) * a.d, true};
}

r64 non_negative_sub(r32 a, r32 b) {
	if(!(a < b)){
		return r64{static_cast<uint64_t>(a.n) * b.d - static_cast<uint64_t>(b.n) * a.d, static_cast<uint64_t>(b.d) * a.d, true};
	} else {
		return r64{static_cast<uint64_t>(b.n) * a.d - static_cast<uint64_t>(a.n) * b.d, static_cast<uint64_t>(b.d) * a.d, false};
	}
}

r64 add(r32 a, r32 b) {
	if(a.p && b.p) {
		return non_negative_add(a, b);
	} else if(a.p && !b.p) {
		return non_negative_sub(a, inverted_r32(b));
	} else if(!a.p && b.p) {
		return inverted_r64(non_negative_sub(inverted_r32(a), b));
	} else {
		return inverted_r64(non_negative_add(a, b));
	}
}

r64 sub(r32 a, r32 b) {
	return add(a, inverted_r32(b));
}

r64 mul(r32 a, r32 b) {
	return r64 {static_cast<uint64_t>(a.n) * b.n, static_cast<uint64_t>(a.d) * b.d, a.p == b.p};
}

r64 div(r32 a, r32 b) {
	return r64 {static_cast<uint64_t>(a.n) * b.d, static_cast<uint64_t>(a.d) * b.n, a.p == b.p};
}

// rational bounds arithmetic
rb32 operator+(const rb32 l, const rb32 r) {
	return rb32{downcast_to_lower_bound(add(l.lb, r.lb)), downcast_to_upper_bound(add(l.ub, r.ub))};
}

rb32 operator-(const rb32 l, const rb32 r) {
	const auto b1 = sub(l.lb, r.lb);
	const auto b2 = sub(l.ub, r.ub);
	if(b1 < b2)
		return rb32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return rb32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

rb32 operator*(const rb32 l, const rb32 r) {
	const auto b1 = mul(l.lb, r.lb);
	const auto b2 = mul(l.ub, r.ub);
	if(b1 < b2)
		return rb32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return rb32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

rb32 operator/(const rb32 l, const rb32 r) {
	const auto b1 = div(l.lb, r.lb);
	const auto b2 = div(l.ub, r.ub);
	if(b1 < b2)
		return rb32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return rb32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

// rational bounds relations
bool coincide(const rb32& l, const rb32& r){
	return l.lb == r.lb && l.ub == r.ub;
}

bool intersect(const rb32& l, const rb32& r){
	return (l.ub >= r.lb && l.lb <= r.ub)
		|| (r.ub >= l.lb && r.lb <= l.ub);
}

// the relation should keep for every number in l to every number in r
bool operator==(const rb32& l, const rb32& r){
	return l.lb == l.ub && coincide(l, r);
}

bool operator<(const rb32& l, const rb32& r){
	return l.ub < r.lb;
}

bool operator>(const rb32& l, const rb32& r){
	return r < l;
}

bool operator<=(const rb32& l, const rb32& r){
	return l.ub < r.lb || l.ub == r.lb;
}

bool operator>=(const rb32& l, const rb32& r){
	return r <= l;
}

bool operator!=(const rb32& l, const rb32& r){
	return r < l || l < r;
}

