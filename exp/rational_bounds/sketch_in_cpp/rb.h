#include <cstdint>
#include <limits>
#include <algorithm>
#include <array>
#include <vector>


using uint128_t = __uint128_t;	// this is non-standard

struct r32 {
	uint32_t n;	// numenator
	uint32_t d;	// denominator
	bool p;	// is positive?
};

struct r64 {
	uint64_t n;	// numenator
	uint64_t d;	// denominator
	bool p;	// is positive?
};

struct rb32 {
	r32 lb;	// lower bound
	r32 ub;	// upper bound
};

bool operator<(const r32& l, const r32& r){
	if(!l.p && r.p) return true;
	if(l.p && !r.p) return false;
	if(!l.p && !r.p) return static_cast<uint64_t>(l.n) * r.d > static_cast<uint64_t>(r.n) * l.d;
	return static_cast<uint64_t>(l.n) * r.d < static_cast<uint64_t>(r.n) * l.d;
}

bool operator<(const r64& l, const r64& r){
	if(!l.p && r.p) return true;
	if(l.p && !r.p) return false;
	if(!l.p && !r.p) return static_cast<uint128_t>(l.n) * r.d > static_cast<uint128_t>(r.n) * l.d;
	return static_cast<uint128_t>(l.n) * r.d < static_cast<uint128_t>(r.n) * l.d;
}

bool operator==(const r32& l, const r32& r){
	return !(l < r || r < l);
}

r32 inverted_r32(r32 x) {
	return r32{x.n, x.d, !x.p};
}

r64 inverted_r64(r64 x) {
	return r64{x.n, x.d, !x.p};
}

r32 downcast_to_lower_bound(r64 x) {
	if(x.n <= std::numeric_limits<uint32_t>::max() && x.d <= std::numeric_limits<uint32_t>::max())
		return r32{static_cast<uint32_t>(x.n), static_cast<uint32_t>(x.d), x.p};
	auto y = r64{x.n, x.d, x.p}; // shifted x
	// todo: fast log
	while(y.n > std::numeric_limits<uint32_t>::max() || y.d > std::numeric_limits<uint32_t>::max()){
		y.n >>= 1;
		y.d >>= 1;
	}
	// todo: figure it out
	std::array<r64, 5> hypotheses{r64{y.n+1, y.d, y.p}, r64{y.n-1, y.d, y.p}, r64{y.n, y.d-1, y.p}, r64{y.n, y.d+1, y.p}, r64{y.n, y.d, y.p}};
	std::vector<r64> not_greater_than_x(hypotheses.size());
	auto last_copy = std::copy_if(hypotheses.begin(), hypotheses.end(), not_greater_than_x.begin(), [&x](const r64& z){return !(x < z);});
	auto best_hypothesis = *std::max_element(not_greater_than_x.begin(), last_copy);
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

rb32 operator+(const rb32 l, const rb32 r) {
	return r32{downcast_to_lower_bound(add(l.lb, r.lb)), downcast_to_upper_bound(add(l.ub, r.ub))};
}

rb32 operator-(const rb32 l, const rb32 r) {
	const auto b1 = sub(l.lb, r.lb);
	const auto b2 = sub(l.ub, r.ub);
	if(b1 < b2)
		return r32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return r32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

rb32 operator*(const rb32 l, const rb32 r) {
	const auto b1 = mul(l.lb, r.lb);
	const auto b2 = mul(l.ub, r.ub);
	if(b1 < b2)
		return r32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return r32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

rb32 operator/(const rb32 l, const rb32 r) {
	const auto b1 = div(l.lb, r.lb);
	const auto b2 = div(l.ub, r.ub);
	if(b1 < b2)
		return r32{downcast_to_lower_bound(b1), downcast_to_upper_bound(b2)};
	else
		return r32{downcast_to_lower_bound(b2), downcast_to_upper_bound(b1)};
}

