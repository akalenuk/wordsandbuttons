#include <cassert>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <iostream>

#define MEASURE(CODE_TO_MEASURE) \
    { \
    auto start = std::chrono::system_clock::now(); \
    CODE_TO_MEASURE \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count(); \
    }


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
    Result_or_code(const ECode& c) {code = c;}
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
    size_t errors = 0;
    size_t results = 0;
    std::cout << "3 comparisons: ";
    MEASURE(
        for(double x = -256.; x < 256.; x += 1./65536.) {
            auto root = sqrt_or_not(x);
            if(root == ECode::INPUT_IS_NAN || root == ECode::INPUT_IS_INFINITE || root == ECode::INPUT_IS_NEGATIVE)
                ++errors;
            else
                ++results;
        }
    );
    std::cout << "\nsanity check: " << ((errors == results) == 1. ? "passed" : "not passed!") << "\n" << std::endl;
}
