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
	// rational arithmetics
	if(true){ // add
		const auto a = r32{1, 2, true};
		const auto b = r32{1, 3, true};
		const auto c = add(a, b);
		assert((c == r64{5, 6, true}));
		const auto d = r32{1, 3, false};
		const auto e = add(a, d);
		assert((e == r64{1, 6, true}));
		const auto f = r32{1, 2, false};
		const auto g = add(f, b);
		assert((g == r64{1, 6, false}));
		const auto h = add(f, d);
		assert((h == r64{5, 6, false}));
	}
	if(true){ // sub
		const auto a = r32{1, 2, true};
		const auto b = r32{1, 3, true};
		const auto c = sub(a, b);
		assert((c == r64{1, 6, true}));
		const auto d = r32{1, 3, false};
		const auto e = sub(a, d);
		assert((e == r64{5, 6, true}));
		const auto f = r32{1, 2, false};
		const auto g = sub(f, b);
		assert((g == r64{5, 6, false}));
		const auto h = sub(f, d);
		assert((h == r64{1, 6, false}));
	}
	if(true){ // mul
		const auto a = r32{1, 2, true};
		const auto b = r32{1, 3, true};
		const auto c = mul(a, b);
		assert((c == r64{1, 6, true}));
		const auto d = r32{1, 3, false};
		const auto e = mul(a, d);
		assert((e == r64{1, 6, false}));
		const auto f = r32{1, 2, false};
		const auto g = mul(f, b);
		assert((g == r64{1, 6, false}));
		const auto h = mul(f, d);
		assert((h == r64{1, 6, true}));
	}
	if(true){ // div
		const auto a = r32{1, 2, true};
		const auto b = r32{1, 3, true};
		const auto c = div(a, b);
		assert((c == r64{3, 2, true}));
		const auto d = r32{1, 3, false};
		const auto e = div(a, d);
		assert((e == r64{3, 2, false}));
		const auto f = r32{1, 2, false};
		const auto g = div(f, b);
		assert((g == r64{3, 2, false}));
		const auto h = div(f, d);
		assert((h == r64{3, 2, true}));
	}
	// rational bounds arithmetic
	if(true){ // +
		const auto a = rb32{r32{1, 3, true}, r32{2, 3, true}};
		const auto b = rb32{r32{2, 7, true}, r32{5, 9, true}};
		const auto c = a + b;
		assert(coincide(c, rb32{r32{13, 21, true}, r32{11, 9, true}}));
	}
	if(true){ // -
		const auto a = rb32{r32{2, 1, true}, r32{3, 1, true}};
		const auto b = rb32{r32{1, 1, true}, r32{2, 1, true}};
		const auto c = a - b;
		assert(coincide(c, rb32{r32{1, 1, true}, r32{1, 1, true}}));
	}
	if(true){ // - with inverted bounds
		const auto a = rb32{r32{1, 1, true}, r32{2, 1, true}};
		const auto b = rb32{r32{4, 1, false}, r32{2, 1, false}};
		const auto c = a - b;
		assert(coincide(c, rb32{r32{4, 1, true}, r32{5, 1, true}}));
	}
	if(true){ // *
		const auto a = rb32{r32{1, 1, true}, r32{2, 1, true}};
		const auto b = rb32{r32{4, 1, false}, r32{2, 1, false}};
		const auto c = a * b;
		assert(coincide(c, rb32{r32{4, 1, false}, r32{4, 1, false}}));
	}
	if(true){ // /
		const auto a = rb32{r32{1, 1, true}, r32{2, 1, true}};
		const auto b = rb32{r32{4, 1, false}, r32{2, 1, false}};
		const auto c = a / b;
		assert(coincide(c, rb32{r32{1, 1, false}, r32{1, 4, false}}));
	}
	// rational bounds logic
	if(true){	// non-intersecting
		const auto a = rb32{r32{1, 1, true}, r32{2, 1, true}};
		const auto b = rb32{r32{3, 1, true}, r32{4, 1, true}};
		assert(!intersect(a, b));
		assert(!intersect(b, a));
		assert(!coincide(a, b));
		assert(!coincide(b, a));
/*		assert(!(b == a));
		assert(b != a);
		assert(a < b);
		assert(b > a);
		assert(!(a <= b));
		assert(!(b >= a));*/
	}
	if(true){	// intersecting
		const auto a = rb32{r32{1, 1, true}, r32{3, 1, true}};
		const auto b = rb32{r32{2, 1, true}, r32{4, 1, true}};
		assert(intersect(a, b));
		assert(intersect(b, a));
		assert(!coincide(a, b));
		assert(!coincide(b, a));
/*		assert(!(b == a));
		assert(!(b != a));
		assert(!(a < b));
		assert(!(b > a));
		assert(!(a <= b));
		assert(!(b >= a));*/
	}
	if(true){	// coinciding
		const auto a = rb32{r32{1, 1, true}, r32{4, 1, true}};
		const auto b = rb32{r32{1, 1, true}, r32{4, 1, true}};
		assert(intersect(a, b));
		assert(intersect(b, a));
		assert(coincide(a, b));
		assert(coincide(b, a));
/*		assert(b == a);
		assert(!(b != a));
		assert(!(a < b));
		assert(!(b > a));
		assert(a <= b);
		assert(b >= a);*/
	}
	return 0;
}
