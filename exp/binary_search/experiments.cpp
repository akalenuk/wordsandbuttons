#include "generate_test_data.h"
#include "measure.h"
#include "find.h"

const size_t sample_size = 10000019;

int main() {
    std::cout << "Different percentage on uniform non-random data\n";
    auto test_data = uniform(sample_size, 0, sample_size-1);
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");

    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "interpolation");



    std::cout << "Different percentage on uniform random data\n";
    test_data = uniform_random(sample_size, 0, sample_size-1);
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");

    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "interpolation");



    std::cout << "Different percentage on skewed data\n";
    test_data = skewed_to_high_end_random(sample_size, 0, sample_size-1);
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");

    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "interpolation");



    std::cout << "Different percentage on low middle data\n";
    test_data = less_in_the_middle_random(sample_size, 0, sample_size-1);
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");    

    MEASURE(
    for(auto i = 0; i < sample_size; ++i) {
        auto index = find_by_interpolation(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "interpolation");



    return 0;
}

