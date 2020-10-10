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
	// downcast
	if(true) {
		auto a = r64{5000000029u, 5100000011u, true};
		auto b = downcast_to_lower_bound(a);
		assert(b.n == 2500000014);
		assert(b.d == 2550000005);
	}
	return 0;
}
