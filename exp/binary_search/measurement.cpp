#include "generate_test_data.h"
#include "measure.h"
#include "find.h"

const size_t sample_size = 10000019;
int _;

int main() {
    std::cout << "Different percentage on uniform non-random data\n";
    auto test_data = uniform(sample_size, 0, sample_size-1);
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index == NONE || test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }

    std::cout << "Different switching percentage on uniform random data\n";
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_switching_percentage(i, test_data, percent, _);
            if(index == NONE || test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }
    
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " interpolation\n";

    auto polynomial = dP(polynomial_for(test_data, 3));
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_polynomial(i, test_data, polynomial, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " polynomial\n\n"; 



    std::cout << "Different percentage on uniform random data\n";
    test_data = uniform_random(sample_size, 0, sample_size-1);
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }

    std::cout << "Different swithcing percentage on uniform random data\n";
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_switching_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }

    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " interpolation\n";

    polynomial = dP(polynomial_for(test_data, 3));
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_polynomial(i, test_data, polynomial, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " polynomial\n\n"; 



    std::cout << "Different percentage on skewed data\n";
    test_data = skewed_to_high_end_random(sample_size, 0, sample_size-1);
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }

    std::cout << "Different swithing percentage on skewed data\n";
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }
    
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " interpolation\n";

    polynomial = dP(polynomial_for(test_data, 3));
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_polynomial(i, test_data, polynomial, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " polynomial\n\n"; 




    std::cout << "Different percentage on low middle data\n";
    test_data = less_in_the_middle_random(sample_size, 0, sample_size-1);
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }

    std::cout << "Different swithing percentage on low middle data\n";
    for(auto percent = 10; percent <= 90; percent += 10) {
        MEASURE(
        for(auto i = 0; i < sample_size; ++i) {
            auto index = find_by_percentage(i, test_data, percent, _);
            if(index != NONE && test_data[index] != i)
                std::cout << "search is faulty\n";
        });
        std::cout << " " << percent << "/" << 100 - percent << "\n";
    }
    
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " interpolation\n";
    
    polynomial = dP(polynomial_for(test_data, 3));
    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_polynomial(i, test_data, polynomial, _);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    });
    std::cout << " polynomial\n\n";    


    return 0;
}

