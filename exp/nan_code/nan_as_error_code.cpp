#include <cassert>
#include <cmath>
#include <cstdint>

enum class ECode : uint64_t {
    INPUT_IS_NAN = 0xFFF0'0000'0000'0001,
    INPUT_IS_INFINITE,
    INPUT_IS_NEGATIVE
};

union Result_or_code
{
    double result;
    ECode code;
    Result_or_code(double x) {result = x;}
    Result_or_code(ECode c) {code = c;}
    operator double() {return result;}
    operator ECode() {return code;}
};

Result_or_code sqrt_or_not(double x) {
    if (std::isnan(x))
        return ECode::INPUT_IS_NAN;
    if (std::isinf(x))
        return ECode::INPUT_IS_INFINITE;
    if(x < 0)
        return ECode::INPUT_IS_NEGATIVE;
    return std::sqrt(x);
}

int main(void) {
    assert(sqrt_or_not(-1.) == ECode::INPUT_IS_NEGATIVE);
    assert(sqrt_or_not(1./0.) == ECode::INPUT_IS_INFINITE);
    assert(sqrt_or_not(0./0.) == ECode::INPUT_IS_NAN);
    assert(sqrt_or_not(4.) == 2.);
}
