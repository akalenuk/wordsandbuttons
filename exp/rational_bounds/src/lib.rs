// Subset of rational numbers in u32/u32
struct R32 {
    n : u32,  // numerator
    d : u32,  // denominator
    f : bool, // finite
    p : bool  // positive
}

// Rational bounds structure
struct RB32 {
    lb : R32, // lower bound
    ub : R32  // upper bound
}

fn simplify(x: R32) -> R32 {
    if !x.f || x.n == 0 { 
        x
    } else {
        fn gcd(a:u32, b:u32) -> u32 {
            if a > b {gcd(a - b, b)}
            else if a < b {gcd(a, b - a)}
            else {a}
        }
        let cd = gcd(x.n, x.d); // common divisor
        if cd == 1 { 
            x
        } else {
            simplify(R32{n: x.n / cd, d: x.d / cd, f: true, p: x.p})
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn simplification_stops() {
        let simplifiable = R32{n:0, d:1, f:true, p:true};
        let simplified = simplify(simplifiable);
        assert_eq!(simplified.n, 0);
        assert_eq!(simplified.d, 1);
    }

    #[test]
    fn simplification_works() {
        let simplifiable = R32{n:3*5*7*11, d:2*5*7*13, f:true, p:true};
        let simplified = simplify(simplifiable);
        assert_eq!(simplified.n, 3*11);
        assert_eq!(simplified.d, 2*13);
    }
}