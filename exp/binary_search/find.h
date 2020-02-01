#include <algorithm>
#include <vector>

static const size_t NONE = std::numeric_limits<size_t>::max();

size_t find_by_percentage(const int what, const std::vector<int>& where, size_t from, size_t to, int percent, int& depth) {
    ++depth;
    if(where[from] == what)
        return from;
    if(to < from + 1)
        return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to);
    if(where[mid] < what)
        return find_by_percentage(what, where, mid + 1, to, percent, depth);
    return find_by_percentage(what, where, from, mid, percent, depth);
}

size_t find_by_percentage(const int what, const std::vector<int>& where, int percent, int& depth) {
    return find_by_percentage(what, where, 0, where.size() - 1, percent, depth);
}


size_t find_by_switching_percentage(const int what, const std::vector<int>& where, size_t from, size_t to, int percent, int& depth) {
    ++depth;
    if(where[from] == what)
        return from;
    if(to < from + 1)
        return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to);
    if(where[mid] < what)
        return find_by_switching_percentage(what, where, mid + 1, to, 100-percent, depth);
    return find_by_switching_percentage(what, where, from, mid, 100-percent, depth);
}

size_t find_by_switching_percentage(const int what, const std::vector<int>& where, int percent, int& depth) {
    return find_by_switching_percentage(what, where, 0, where.size() - 1, percent, depth);
}


size_t find_by_interpolation(const int what, const std::vector<int>& where, size_t from, size_t to, int& depth) {
    ++depth;
    if(to < from + 1)
        return NONE;
    if (where[from] == what)
        return from;
    if (where[to] == what)
        return to;
    double t = static_cast<double>(what - where[from]) / static_cast<double>(where[to] - where[from]);
    t = std::max(t, 0.);
    t = std::min(t, 1.);
    size_t mid = from + static_cast<size_t>((to - from) * t);
    if (where[mid] < what)
        return find_by_interpolation(what, where, mid + 1, to, depth);
    return find_by_interpolation(what, where, from, mid, depth);
}

size_t find_by_interpolation(const int what, const std::vector<int>& where, int& depth) {
    return find_by_interpolation(what, where, 0, where.size() - 1, depth);
}


std::vector<double> solve(std::vector<std::vector<double>>& A, std::vector<double>& B) {
    const auto n = B.size();

    // triangulize
    for (auto i = 0u; i < n-1; ++i)
        for (auto j = 0u; j < i+1; ++j) {
            const auto r = A[i+1][j] / A[j][j];
            A[i+1][j] = 0.;
            for (auto b_j = j+1; b_j < n; ++b_j) {
                A[i+1][b_j] -= A[j][b_j]*r;
            }
            B[i+1] -= B[j]*r;
        }

    // calculate xs
    std::vector<double> X(n, 0.);
    X[n-1] = B[n-1] / A[n-1][n-1];
    for (signed int i = n-2; i >= 0; --i) {
        auto s = 0.0;
        for (auto j = i; j < n; ++j) {
            s = s + A[i][j]*X[j];
        }
        X[i] = (B[i] - s) / A[i][i];
    }
    return X;
}

std::vector<double> polynomial_for(std::vector<int>& where, unsigned int n) {
    std::vector<std::vector<double>> A(n);
    for (auto& Ai : A)
        Ai.resize(n, 0.);
    std::vector<double> B(n, 0.);

    for (auto i = 0u; i < n; ++i) {
        auto& Ai = A[i];
        for (auto j = 0u; j < n; ++j) {
            for(auto k = 0u; k < where.size(); ++k) {
                Ai[j] += std::pow(where[k], i + j);
            }
        }

        for(auto k = 0u; k < where.size(); ++k) {
            B[i] += k * std::pow(where[k], i);
        }
    }
    return solve(A, B);
}

double Px(const std::vector<double>& P, double x) {
    double y = 0.;
    for(auto i = 0u; i < P.size(); ++i) {
        y += P[i] * std::pow(x, i);
    }
    return y;
}

size_t find_by_polynomial(const int what, const std::vector<int>& where, size_t from, size_t to, const std::vector<double>& polynomial, int& depth) {
    ++depth;
    if(to < from + 1)
        return NONE;
    if (where[from] == what)
        return from;
    if (where[to] == what)
        return to;
        
    // polynomial "derivative"
    static const double PI = 3.1415926;
    double dPx = (Px(polynomial, to) - Px(polynomial, from)) / (to - from);
    double t = std::atan(dPx) / (PI / 2.);
    
    t = std::max(t, 0.);
    t = std::min(t, 1.);
    size_t mid = from + static_cast<size_t>((to - from) * t);
    if (where[mid] < what)
        return find_by_polynomial(what, where, mid + 1, to, polynomial, depth);
    return find_by_polynomial(what, where, from, mid, polynomial, depth);
}

size_t find_by_polynomial(const int what, const std::vector<int>& where, const std::vector<double>& polynomial, int& depth) {
    return find_by_polynomial(what, where, 0, where.size() - 1, polynomial, depth);
}

