#include "rb.h"
#include <cassert>

int main(void) {
	// less predicate
	if(true){
		auto a = r32{1, 5, true};
		auto b = r32{2, 9, true};
		auto na = r32{1, 5, false};
		auto nb = r32{2, 9, false};
		assert(a < b);
		assert(na < a);
		assert(!(b < na));
		assert(nb < na);
	}
	// equality
	if(true) {
		auto a = r32{1, 5, true};
		auto b = r32{2, 10, true};
		assert(a == b);
	}
	// downcast
	if(true) {
		auto a = r64{5000000029ull, 5100000011ull, true};
		auto b = downcast_to_lower_bound(a);
		assert(b.n == 2500000014ull);
		assert(b.d == 2550000005ull);

		for(uint64_t dan = 0; dan < 2500000000ull; dan += 500000000ull) {
			for(uint64_t dad = 0; dad < 2500000000ull; dad += 500000000ull) {
				auto na = r64{a.n + dan, a.d + dad, a.p};
				auto lower_na = downcast_to_lower_bound(na);
				auto upper_na = downcast_to_upper_bound(na);
				auto lower_na64 = r64{lower_na.n, lower_na.d, lower_na.p};
				auto upper_na64 = r64{upper_na.n, upper_na.d, upper_na.p};
				assert(!(na < lower_na64));
				assert(!(upper_na64 < na));
			}
		}
	}
	return 0;
}
