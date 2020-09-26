// Subset of rational numbers in u32/u32
struct R32 {
    n : u32,  // numerator
    d : u32,  // denominator
    f : bool, // finite
    p : bool  // positive
}

// Rational bounds structure
struct RB {
    lb : R32, // lower bound
    ub : R32  // upper bound
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}