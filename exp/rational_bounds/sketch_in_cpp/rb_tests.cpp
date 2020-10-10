#include "rb.h"
#include <cassert>

int main(void) {
	auto a = r32{1, 5, true};
	auto b = r32{2, 9, true};
	assert(a < b);	// less predicate
	return 0;
}
