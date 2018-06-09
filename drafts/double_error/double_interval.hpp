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
    
    DoubleInterval& operator+=(const DoubleInterval& rhs)
    {
        from = static_cast<double>(this->from) + static_cast<double>(rhs.from);
        to = static_cast<double>(this->to) + static_cast<double>(rhs.to);
        return *this;
    }
    friend DoubleInterval operator+(DoubleInterval lhs, const DoubleInterval& rhs)
    {
        lhs += rhs;
        return lhs;
    }
  
    DoubleInterval& operator-=(const DoubleInterval& rhs)
    {
        from = static_cast<double>(this->from) - static_cast<double>(rhs.to);
        to = static_cast<double>(this->to) - static_cast<double>(rhs.from);
        return *this;
    }
    friend DoubleInterval operator-(DoubleInterval lhs, const DoubleInterval& rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    
    DoubleInterval& operator*=(const DoubleInterval& rhs)
    {
        long double aa = static_cast<double>(this->from) * static_cast<double>(rhs.from);
        long double ab = static_cast<double>(this->from) * static_cast<double>(rhs.to);
        long double ba = static_cast<double>(this->to) * static_cast<double>(rhs.from);
        long double bb = static_cast<double>(this->to) * static_cast<double>(rhs.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        return *this;
    }
    friend DoubleInterval operator*(DoubleInterval lhs, const DoubleInterval& rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    
    DoubleInterval& operator/=(const DoubleInterval& rhs)
    {
        long double aa = static_cast<double>(this->from) / static_cast<double>(rhs.from);
        long double ab = static_cast<double>(this->from) / static_cast<double>(rhs.to);
        long double ba = static_cast<double>(this->to) / static_cast<double>(rhs.from);
        long double bb = static_cast<double>(this->to) / static_cast<double>(rhs.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        return *this;
    }
    friend DoubleInterval operator/(DoubleInterval lhs, const DoubleInterval& rhs)
    {
        lhs /= rhs;
        return lhs;
    }

    
    DoubleInterval operator+=(const double rhs)
    {
        return *this + DoubleInterval(rhs);
    }
    DoubleInterval operator-=(const double rhs)
    {
        return *this - DoubleInterval(rhs);
    }
    DoubleInterval operator*=(const double rhs)
    {
        return *this * DoubleInterval(rhs);
    }
    DoubleInterval operator/=(const double rhs)
    {
        return *this / DoubleInterval(rhs);
    }  
    
    operator double() 
    {
    return static_cast<double>(from);
    }
};

DoubleInterval operator+(DoubleInterval lhs, const double& rhs)
{
    return lhs + DoubleInterval(rhs);
}
DoubleInterval operator-(DoubleInterval lhs, const double& rhs)
{
    return lhs - DoubleInterval(rhs);
}
DoubleInterval operator*(DoubleInterval lhs, const double& rhs)
{
    return lhs * DoubleInterval(rhs);
}
DoubleInterval operator/(DoubleInterval lhs, const double& rhs)
{
    return lhs / DoubleInterval(rhs);
}

DoubleInterval operator+(double lhs, const DoubleInterval& rhs)
{
    return DoubleInterval(lhs) + rhs;
}
DoubleInterval operator-(double lhs, const DoubleInterval& rhs)
{
    return DoubleInterval(lhs) - rhs;
}
DoubleInterval operator*(double lhs, const DoubleInterval& rhs)
{
    return DoubleInterval(lhs) * rhs;
}
DoubleInterval operator/(double lhs, const DoubleInterval& rhs)
{
    return DoubleInterval(lhs) / rhs;
}

// this selects a minimum and a maximum on an interval divided into a number of segments
#define SEGMENTS 10 // 10 is arbitarary, we just want to have some approximation
#define std_monadic_function(name) \
    DoubleInterval name (DoubleInterval x) \
    { \
        long double a_min = std:: name (static_cast<double>(x.from)); \
        long double a_max = a_min; \
        for (auto i = 0u; i < SEGMENTS; ++i) { \
           auto xi = x.from + (i + 1) * (x.to - x.from) / SEGMENTS; \
	   long double ai = std:: name (static_cast<double>(xi)); \
\
           if (isnan(a_min)) \
               a_min = ai; \
           else \
               if (!isnan(ai)) \
                   a_min = std::min(a_min, ai); \
\
           if (isnan(a_max)) \
               a_max = ai; \
           else \
               if (!isnan(ai)) \
                   a_max = std::max(a_max, ai); \
        } \
        return DoubleInterval(a_min, a_max); \
    }
    
namespace std {
    std_monadic_function(sqrt);
    std_monadic_function(sin);
    std_monadic_function(cos);
    std_monadic_function(tan);
    std_monadic_function(ctg);
    std_monadic_function(asin);    
    std_monadic_function(acos);
    std_monadic_function(atan);
    std_monadic_function(actg);
    std_monadic_function(abs);
    
    template <>
    constexpr DoubleInterval numeric_limits<DoubleInterval>::quiet_NaN() noexcept
    {
        return DoubleInterval(std::numeric_limits<long double>::quiet_NaN(), std::numeric_limits<long double>::quiet_NaN());
    }
}

