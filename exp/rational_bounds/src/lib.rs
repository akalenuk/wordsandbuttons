pub trait U32U64Only {}
impl U32U64Only for u32 {}
impl U32U64Only for u64 {}

// Subset of rational numbers in u32/u32 or u64/u64
#[derive(Copy, Clone)]
struct R<U:U32U64Only> {
	n : U,  // numerator
	d : U,  // denominator
	p : bool  // positive
}

// Rational bounds structure
struct RB32 {
	lb : R<u32>, // lower bound
	ub : R<u32>  // upper bound
}

fn simplify<U>(x: R<U>) -> R<U>
	where U:std::cmp::PartialEq
			+ std::ops::SubAssign
			+ std::cmp::PartialOrd
			+ std::ops::Div<Output = U>
			+ std::convert::From<u32>
			+ std::marker::Copy
			+ U32U64Only
{
	if x.n == U::from(0_u32) || x.d == U::from(0_u32) { 
		x
	} else {
		// recursive GCD can easily eat up all the stack on u64 numbers
		let mut a = x.n;
		let mut b = x.d;
		while a != b {
			if a > b {a -= b;}
			else if a < b {b -= a;}
		}
		let cd = a; // common divisor
		if cd == U::from(1_u32) {
			x
		} else {
			simplify(R::<U>{n: x.n / cd, d: x.d / cd, p: x.p})
		}
	}
}

impl std::cmp::PartialOrd for R<u32> {
	fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
		if self.p && !other.p {
			Some(std::cmp::Ordering::Greater)
		} else if !self.p && other.p {
			Some(std::cmp::Ordering::Less)
		} else {
			// self.p = other.p
			let a = if self.p {self.n as u64 * other.d as u64} else {other.n as u64 * self.d as u64};
			let b = if other.p {other.n as u64 * self.d as u64} else {self.n as u64 * other.d as u64};
			Some(a.cmp(&b))
		}
	}
}

impl std::cmp::PartialEq for R<u32> {
	fn eq(&self, other: &Self) -> bool {
		self.p == other.p && self.n == other.n && self.d == other.d
	}
}

impl std::cmp::PartialOrd for R<u64> {
	fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
		if self.p && !other.p {
			Some(std::cmp::Ordering::Greater)
		} else if !self.p && other.p {
			Some(std::cmp::Ordering::Less)
		} else {
			// self.p = other.p
			let a = if self.p {self.n as u128 * other.d as u128} else {other.n as u128 * self.d as u128};
			let b = if other.p {other.n as u128 * self.d as u128} else {self.n as u128 * other.d as u128};
			Some(a.cmp(&b))
		}
	}
}

impl std::cmp::PartialEq for R<u64> {
	fn eq(&self, other: &Self) -> bool {
		self.p == other.p && self.n == other.n && self.d == other.d
	}
}

fn upcast(x: R<u32>) -> R<u64>
{
	R::<u64>{n: x.n as u64, d: x.d as u64, p: x.p}
}

fn downcast_to_lower_bound(x: R<u64>) -> R<u32>
{
	let simple_x = simplify(x);
	let mut n = simple_x.n;
	let mut d = simple_x.d;
	let p = simple_x.p;
	while n > u32::MAX.into() || d > u32::MAX.into() {
		n >>= 1;
		d >>= 1;
	}
	// lower bound (there is a specific logic behind that but I can't get it right so I'd just test all the variants)
	let hypothesis1 = R::<u64>{n: n, d: d, p: p};
	let hypothesis2 = R::<u64>{n: (n - 1), d: d, p: p};
	let hypothesis3 = R::<u64>{n: n, d: (d + 1), p: p};
	let hypothesis4 = R::<u64>{n: (n + 1), d: d, p: p};
	let hypothesis5 = R::<u64>{n: n, d: (d - 1), p: p};
	let mut hypotheses = Vec::new();
	if hypothesis1 <= simple_x {hypotheses.push(hypothesis1);}
	if hypothesis2 <= simple_x {hypotheses.push(hypothesis2);}
	if hypothesis3 <= simple_x {hypotheses.push(hypothesis3);}
	if hypothesis4 <= simple_x {hypotheses.push(hypothesis4);}
	if hypothesis5 <= simple_x {hypotheses.push(hypothesis5);}
	let best_of_three = hypotheses.iter().max_by(|x, y|
		if x <= y && x >= y {std::cmp::Ordering::Equal}
		else if x <= y {std::cmp::Ordering::Less}
		else {std::cmp::Ordering::Greater});
	match best_of_three {
		Some(y)	=> if y.n > u32::MAX.into() || y.n > u32::MAX.into()
				{downcast_to_lower_bound(*y)} 
			else 
				{R::<u32>{n: y.n as u32, d: y.d as u32, p: y.p}}
		None	=> panic!("Um. That can't be right."),
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn simplification_stops() {
		let simplifiable = R::<u32>{n:0, d:1, p:true};
		let simplified = simplify(simplifiable);
		assert_eq!(simplified.n, 0);
		assert_eq!(simplified.d, 1);
	}

	#[test]
	fn simplification_works() {
		let simplifiable = R::<u32>{n:3*5*7*11, d:2*5*7*13, p:true};
		let simplified = simplify(simplifiable);
		assert_eq!(simplified.n, 3*11);
		assert_eq!(simplified.d, 2*13);
	}

	#[test]
	fn simplification_works_on_64_bits() {
		let simplifiable = R::<u64>{n:3*5*7*11, d:2*5*7*13, p:true};
		let simplified = simplify(simplifiable);
		assert_eq!(simplified.n, 3*11);
		assert_eq!(simplified.d, 2*13);
	}

	#[test]
	fn comparison_on_r32() {
		let a = R::<u32>{n:1, d:2, p:true};
		let b = R::<u32>{n:3, d:5, p:true};
		assert!(a < b);
		assert!(b > a);
		assert!(a != b);
	}

	#[test]
	fn comparison_on_negative_r32() {
		let a = R::<u32>{n:1, d:2, p:true};
		let b = R::<u32>{n:3, d:5, p:false};
		assert!(a > b);
		assert!(b < a);
		assert!(b != a);
	}

	#[test]
	fn comparison_on_other_negative_r32() {
		let b = R::<u32>{n:1, d:2, p:true};
		let a = R::<u32>{n:3, d:5, p:false};
		assert!(a < b);
		assert!(b > a);
		assert!(b != a);
	}

	#[test]
	fn equality_on_r32() {
		let a = R::<u32>{n:1, d:2, p:true};
		let b = R::<u32>{n:1, d:2, p:true};
		assert!(a == b);
	}

	#[test]
	fn comparison_on_r64() {
		let a = R::<u64>{n:1, d:2, p:true};
		let b = R::<u64>{n:3, d:5, p:true};
		assert!(a < b);
		assert!(b > a);
		assert!(a != b);
	}

	#[test]
	fn equality_on_r64() {
		let a = R::<u64>{n:1, d:2, p:true};
		let b = R::<u64>{n:1, d:2, p:true};
		assert!(a == b);
	}

	#[test]
	fn downcast_doesnt_hang() {
		let a = R::<u64>{n:5000000029 , d: 5100000011, p:true};
		let b = downcast_to_lower_bound(a);
		assert_eq!(b.n, 2500000014);
		assert_eq!(b.d, 2550000005);
	}

	#[test]
	fn downcast_to_lower_bound_downcasts_to_lower() {	// warning! I lack mathematical intuition to do this properly
		for i in 5000000000..5000000099 {
			let a = R::<u64>{n: i , d: i + 100000000, p:true};
			let b = downcast_to_lower_bound(a);
			let c = R::<u64>{n: b.n as u64 , d: b.d as u64, p:true};
			assert!(c <= a);
		}
	}
}
