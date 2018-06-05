#include <cmath>
#include <limits>

struct DoubleInterval 
{
    long double from = 0.;
    long double to = 0.;
    DoubleInterval() = default;
    constexpr DoubleInterval(long double a, long double b) {
        from = a;
        to = b;
    }
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
    
    DoubleInterval operator+=(const double that)
    {
        return *this + that;
    }
    DoubleInterval operator-=(const double that)
    {
        return *this - that;
    }
    DoubleInterval operator*=(const double that)
    {
        return *this * that;
    }
    DoubleInterval operator/=(const double that)
    {
        return *this / that;
    }
    
    DoubleInterval operator+(const double that)
    {
        return *this + DoubleInterval(that);
    }    
    DoubleInterval operator-(const double that)
    {
        return *this - DoubleInterval(that);
    }
    DoubleInterval operator*(const double that)
    {
        return *this * DoubleInterval(that);
    }    
    DoubleInterval operator/(const double that)
    {
        return *this / DoubleInterval(that);
    }
    
    operator double() 
    {
    return static_cast<double>(from);
    }
};

#define std_monadic_function(name) \
    DoubleInterval name (DoubleInterval x) \
    { \
        long double a = std:: name (static_cast<double>(x.from)); \
        long double b = std:: name (static_cast<double>(x.to)); \
        if(a < b) \
            return DoubleInterval(a, b); \
        else \
            return DoubleInterval(b, a); \
    }
    
namespace std {
    std_monadic_function(sqrt);
    std_monadic_function(sin);
    std_monadic_function(cos);
    std_monadic_function(asin);    
    std_monadic_function(acos);
    std_monadic_function(abs);
    
    template <>
    constexpr DoubleInterval numeric_limits<DoubleInterval>::quiet_NaN() noexcept
    {
        return DoubleInterval(std::numeric_limits<long double>::quiet_NaN(), std::numeric_limits<long double>::quiet_NaN());
    }
}

