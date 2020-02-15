#include <cassert>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <tuple>

#define MEASURE(CODE_TO_MEASURE) \
    { \
    auto start = std::chrono::system_clock::now(); \
    CODE_TO_MEASURE \
    auto end = std::chrono::system_clock::now(); \
    std::chrono::duration<double> difference = end - start; \
    std::cout << difference.count(); \
    }


enum class ECode : uint64_t {
    OK = 0xFFF0'0000'0000'0001,
    INPUT_IS_NAN,
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

double sqrt_or_throw(double x) {
    if (std::isnan(x))
        throw std::invalid_argument("");
    if (std::isinf(x))
        throw std::invalid_argument("");
    if(x < 0)
        throw std::domain_error("");
    return std::sqrt(x);
}

std::tuple<ECode, double> code_and_sqrt(double x) {
    if (std::isnan(x))
        return std::make_tuple(ECode::INPUT_IS_NAN, 0.);
    if (std::isinf(x))
        return std::make_tuple(ECode::INPUT_IS_INFINITE, 0.);
    if(x < 0)
        return std::make_tuple(ECode::INPUT_IS_NEGATIVE, 0.);
    return std::make_tuple(ECode::OK, std::sqrt(x));
}

void measure_3_comparisons() {
    size_t errors = 0;
    size_t results = 0;
    double total = 0.;
    std::cout << "3 comparisons: ";
    MEASURE(
        for(double x = -1024.; x <= 1024.; x += 1./65536.) {
            auto root = sqrt_or_not(x);
            if(root == ECode::INPUT_IS_NAN || root == ECode::INPUT_IS_INFINITE || root == ECode::INPUT_IS_NEGATIVE)
                ++errors;
            else {
                ++results;
                total += root;
            }
        }
    );
    std::cout << "\nsanity check: " << ((errors == results - 1) == 1. ? "passed" : "not passed!") << "; sum: " << total << "\n" << std::endl;
}

void measure_isnan() {
    size_t errors = 0;
    size_t results = 0;
    double total = 0.;
    std::cout << "is nan: ";
    MEASURE(
        for(double x = -1024.; x <= 1024.; x += 1./65536.) {
            auto root = sqrt_or_not(x);
            if(std::isnan(root))
                ++errors;
            else {
                ++results;
                total += root;
            }
        }
    );
    std::cout << "\nsanity check: " << ((errors == results - 1) == 1. ? "passed" : "not passed!") << "; sum: " << total << "\n" << std::endl;
}

void measure_non_less_than_error() {
    size_t errors = 0;
    size_t results = 0;
    double total = 0.;
    std::cout << "no less than error: ";
    MEASURE(
        for(double x = -1024.; x <= 1024.; x += 1./65536.) {
            auto root = sqrt_or_not(x);
            if(root >= ECode::INPUT_IS_NAN)
                ++errors;
            else {
                ++results;
                total += root;
            }
        }
    );
    std::cout << "\nsanity check: " << ((errors == results - 1) == 1. ? "passed" : "not passed!") << "; sum: " << total << "\n" << std::endl;
}

void measure_tuple() {
    size_t errors = 0;
    size_t results = 0;
    double total = 0.;
    std::cout << "tuple: ";
    MEASURE(
        for(double x = -1024.; x <= 1024.; x += 1./65536.) {
            auto code_and_root = code_and_sqrt(x);
            if(std::get<0>(code_and_root) != ECode::OK)
                ++errors;
            else {
                ++results;
                total += std::get<1>(code_and_root);
            }
        }
    );
    std::cout << "\nsanity check: " << ((errors == results - 1) == 1. ? "passed" : "not passed!") << "; sum: " << total << "\n" << std::endl;
}

void measure_throw() {
    size_t errors = 0;
    size_t results = 0;
    double total = 0.;
    std::cout << "throw (512 less experiments!): ";
    MEASURE(
        for(double x = -2.; x <= 2.; x += 1./65536.) {
            try {
                auto root = sqrt_or_throw(x);
                total += root;
                ++results;
            } catch (const std::logic_error& e) {
                ++errors;
            }
        }
    );
    std::cout << "\nsanity check: " << ((errors == results - 1) == 1. ? "passed" : "not passed!") << "; sum: " << total << "\n" << std::endl;
}


int main(void) {
    measure_3_comparisons();
    measure_isnan();
    measure_non_less_than_error();
    measure_tuple();
    measure_throw();
}
