#include <cstdint>
#include <limits>

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

r32 downcast_to_lower_bound(r64 x) {
	if(x.n <= std::numeric_limits<uint32_t>::max() && x.d <= std::numeric_limits<uint32_t>::max())
		return r32{static_cast<uint32_t>(x.n), static_cast<uint32_t>(x.d), x.p};
	// todo: fast log
	while(x.n > std::numeric_limits<uint32_t>::max() || x.d > std::numeric_limits<uint32_t>::max()){
		x.n >>= 1;
		x.d >>= 1;
	}
	// temp
	return r32{static_cast<uint32_t>(x.n), static_cast<uint32_t>(x.d), x.p};
}

