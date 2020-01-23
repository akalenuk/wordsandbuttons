#include "generate_test_data.h"
#include "measure.h"
#include "find.h"

int main() {
    std::cout << "Different percentage on uniform data\n";
    auto test_data = uniform_random(10'000'000, 0, 10'000'000-1);
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");


    std::cout << "Different percentage on skewed data\n";
    test_data = skewed_to_high_end_random(10'000'000, 0, 10'000'000-1);
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");


    std::cout << "Different percentage on low middle data\n";
    test_data = less_in_the_middle_random(10'000'000, 0, 10'000'000-1);
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<10>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "10/90");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<20>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "20/80");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<30>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "30/70");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<40>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "40/60");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "50 / 50");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<60>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "60/40");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<70>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "70/30");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<80>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "80/20");
    MEASURE(    
    for(auto i = 0; i < 10'000'000; ++i) {
        auto index = find_by_percentage<90>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "search is faulty\n";
    }
    , "90/10");    

    return 0;
}

