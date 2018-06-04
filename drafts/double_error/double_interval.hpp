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
        from = static_cast<double>(this->from) + static_cast<double>(that.from);
        to = static_cast<double>(this->to) + static_cast<double>(that.to);
        return *this;
    }
    DoubleInterval operator-(const DoubleInterval& that)
    {
        from = static_cast<double>(this->from) - static_cast<double>(that.to);
        to = static_cast<double>(this->to) - static_cast<double>(that.from);
        return *this;
    }
    DoubleInterval operator*(const DoubleInterval& that)
    {
        long double aa = static_cast<double>(this->from) * static_cast<double>(that.from);
        long double ab = static_cast<double>(this->from) * static_cast<double>(that.to);
        long double ba = static_cast<double>(this->to) * static_cast<double>(that.from);
        long double bb = static_cast<double>(this->to) * static_cast<double>(that.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        return *this;
    }
    DoubleInterval operator/(const DoubleInterval& that)
    {
        long double aa = static_cast<double>(this->from) / static_cast<double>(that.from);
        long double ab = static_cast<double>(this->from) / static_cast<double>(that.to);
        long double ba = static_cast<double>(this->to) / static_cast<double>(that.from);
        long double bb = static_cast<double>(this->to) / static_cast<double>(that.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        return *this;
    }
    operator double() 
    {
    return static_cast<double>(from);
    }
};

