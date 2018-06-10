#include <cmath>
#include <limits>
#include <functional>

struct DoubleInterval 
{
    long double from = 0.l;
    long double to = 0.l;
    double original = 0.;

    DoubleInterval() = default;
    constexpr DoubleInterval(long double a, long double b, double x) {
        from = a;
        to = b;
	original = x;
    }
    DoubleInterval(double x) {
        from = x;
        to = std::nextafter<double>(x, std::numeric_limits<double>::max());
        original = x;
    }
    
    DoubleInterval& operator+=(const DoubleInterval& rhs) {
        from = static_cast<double>(this->from) + static_cast<double>(rhs.from);
        to = static_cast<double>(this->to) + static_cast<double>(rhs.to);
        original = original + rhs.original;
        return *this;
    }
    friend DoubleInterval operator+(DoubleInterval lhs, const DoubleInterval& rhs) {
        lhs += rhs;
        return lhs;
    }
  
    DoubleInterval& operator-=(const DoubleInterval& rhs) {
        from = static_cast<double>(this->from) - static_cast<double>(rhs.to);
        to = static_cast<double>(this->to) - static_cast<double>(rhs.from);
        original = original - rhs.original;
        return *this;
    }
    friend DoubleInterval operator-(DoubleInterval lhs, const DoubleInterval& rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    DoubleInterval& operator*=(const DoubleInterval& rhs) {
        long double aa = static_cast<double>(this->from) * static_cast<double>(rhs.from);
        long double ab = static_cast<double>(this->from) * static_cast<double>(rhs.to);
        long double ba = static_cast<double>(this->to) * static_cast<double>(rhs.from);
        long double bb = static_cast<double>(this->to) * static_cast<double>(rhs.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        original = original * rhs.original;
        return *this;
    }
    friend DoubleInterval operator*(DoubleInterval lhs, const DoubleInterval& rhs) {
        lhs *= rhs;
        return lhs;
    }
    
    DoubleInterval& operator/=(const DoubleInterval& rhs) {
        long double aa = static_cast<double>(this->from) / static_cast<double>(rhs.from);
        long double ab = static_cast<double>(this->from) / static_cast<double>(rhs.to);
        long double ba = static_cast<double>(this->to) / static_cast<double>(rhs.from);
        long double bb = static_cast<double>(this->to) / static_cast<double>(rhs.to);
        from = std::min(aa, std::min(ab, std::min(ba, bb)));
        to = std::max(aa, std::max(ab, std::max(ba, bb)));
        original = original / rhs.original;
        return *this;
    }
    friend DoubleInterval operator/(DoubleInterval lhs, const DoubleInterval& rhs) {
        lhs /= rhs;
        return lhs;
    }

    
    DoubleInterval operator+=(const double rhs) {
        return *this + DoubleInterval(rhs);
    }
    DoubleInterval operator-=(const double rhs) {
        return *this - DoubleInterval(rhs);
    }
    DoubleInterval operator*=(const double rhs) {
        return *this * DoubleInterval(rhs);
    }
    DoubleInterval operator/=(const double rhs) {
        return *this / DoubleInterval(rhs);
    }  
    
    operator double() {
        return original;
    }
};

DoubleInterval operator+(DoubleInterval lhs, const double& rhs) {
    return lhs + DoubleInterval(rhs);
}
DoubleInterval operator-(DoubleInterval lhs, const double& rhs) {
    return lhs - DoubleInterval(rhs);
}
DoubleInterval operator*(DoubleInterval lhs, const double& rhs) {
    return lhs * DoubleInterval(rhs);
}
DoubleInterval operator/(DoubleInterval lhs, const double& rhs) {
    return lhs / DoubleInterval(rhs);
}

DoubleInterval operator+(double lhs, const DoubleInterval& rhs) {
    return DoubleInterval(lhs) + rhs;
}
DoubleInterval operator-(double lhs, const DoubleInterval& rhs) {
    return DoubleInterval(lhs) - rhs;
}
DoubleInterval operator*(double lhs, const DoubleInterval& rhs) {
    return DoubleInterval(lhs) * rhs;
}
DoubleInterval operator/(double lhs, const DoubleInterval& rhs) {
    return DoubleInterval(lhs) / rhs;
}

namespace {
// this selects a minimum and a maximum on an interval divided into a number of segments
    static const unsigned int g_num_of_segments = 10; // 10 is arbitarary, we just want to have some approximation
    
    DoubleInterval run_std(DoubleInterval x, std::function<double(double)> fun) {
        long double a_min = fun(static_cast<double>(x.from));
        long double a_max = a_min;
        for (auto i = 0u; i < g_num_of_segments; ++i) {
           auto xi = x.from + (i + 1) * (x.to - x.from) / g_num_of_segments;
	   long double ai = fun(static_cast<double>(xi));

           if (std::isnan(a_min))
               a_min = ai;
           else
               if (! std::isnan(ai))
                   a_min = std::min(a_min, ai);

           if (std::isnan(a_max))
               a_max = ai;
           else
               if (! std::isnan(ai))
                   a_max = std::max(a_max, ai);
        }
        double original = fun(x);
        return DoubleInterval(a_min, a_max, original);
    }
}

#define std_monadic_function(name) \
    DoubleInterval name (DoubleInterval x) { \
        return run_std(x, [](double x) -> double {return std:: name(x);}); \
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
        return DoubleInterval(
            std::numeric_limits<long double>::quiet_NaN(), 
            std::numeric_limits<long double>::quiet_NaN(),
            std::numeric_limits<double>::quiet_NaN());
    }
}

