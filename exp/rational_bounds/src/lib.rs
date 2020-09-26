pub trait U32U64Only {}
impl U32U64Only for u32 {}
impl U32U64Only for u64 {}

// Subset of rational numbers in u32/u32 or u64/u64
struct R<U:U32U64Only> {
    n : U,  // numerator
    d : U,  // denominator
    f : bool, // finite
    p : bool  // positive
}

// Rational bounds structure
struct RB32 {
    lb : R<u32>, // lower bound
    ub : R<u32>  // upper bound
}

fn simplify<U>(x: R<U>) -> R<U> 
    where U:std::cmp::PartialEq
           + std::ops::Sub<Output = U>
           + std::cmp::PartialOrd
           + std::ops::Div<Output = U>
           + std::convert::From<u32>
           + std::marker::Copy
           + U32U64Only
{
    if !x.f || x.n == U::from(0_u32) { 
        x
    } else {
        fn gcd<U>(a:U, b:U) -> U 
            where U: std::ops::Sub<Output = U>
                   + std::cmp::PartialOrd
                   + Copy
        {
            if a > b {gcd(a - b, b)}
            else if a < b {gcd(a, b - a)}
            else {a}
        }
        let cd = gcd(x.n, x.d); // common divisor
        if cd == U::from(1_u32) {
            x
        } else {
            simplify(R::<U>{n: x.n / cd, d: x.d / cd, f: true, p: x.p})
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn simplification_stops() {
        let simplifiable = R::<u32>{n:0, d:1, f:true, p:true};
        let simplified = simplify(simplifiable);
        assert_eq!(simplified.n, 0);
        assert_eq!(simplified.d, 1);
    }

    #[test]
    fn simplification_works() {
        let simplifiable = R::<u32>{n:3*5*7*11, d:2*5*7*13, f:true, p:true};
        let simplified = simplify(simplifiable);
        assert_eq!(simplified.n, 3*11);
        assert_eq!(simplified.d, 2*13);
    }

    #[test]
    fn simplification_works_on_64_bits() {
        let simplifiable = R::<u64>{n:3*5*7*11, d:2*5*7*13, f:true, p:true};
        let simplified = simplify(simplifiable);
        assert_eq!(simplified.n, 3*11);
        assert_eq!(simplified.d, 2*13);
    }
}
