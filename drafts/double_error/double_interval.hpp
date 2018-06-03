#include <cmath>
#include <limits>

struct DoubleInterval 
{
    long double from;
    long double to;
    DoubleInterval(double x) {
        from = x;
        to = std::nextafter<double>(x, std::numeric_limits<double>::max());
    }
    DoubleInterval operator+(const DoubleInterval& that)
    {
        from = this->from + that.from;
        to = this->to + that.to;
        return *this;
    }
};

