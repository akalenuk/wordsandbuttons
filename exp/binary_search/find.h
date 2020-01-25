#include <algorithm>
#include <vector>

static const size_t NONE = std::numeric_limits<size_t>::max();

size_t find_by_percentage(const int what, const std::vector<int>& where, size_t from, size_t to, int percent) {
    if(where[from] == what)
        return from;
    if(to - from < 1)
        return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to);
    if(where[mid] < what)
        return find_by_percentage(what, where, mid + 1, to, percent);
    return find_by_percentage(what, where, from, mid, percent);
}

size_t find_by_percentage(const int what, const std::vector<int>& where, int percent) {
    return find_by_percentage(what, where, 0, where.size() - 1, percent);
}


size_t find_by_switching_percentage(const int what, const std::vector<int>& where, size_t from, size_t to, int percent) {
    if(where[from] == what)
        return from;
    if(to - from < 1)
        return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to);
    if(where[mid] < what)
        return find_by_switching_percentage(what, where, mid + 1, to, 100-percent);
    return find_by_switching_percentage(what, where, from, mid, 100-percent);
}

size_t find_by_switching_percentage(const int what, const std::vector<int>& where, int percent) {
    return find_by_switching_percentage(what, where, 0, where.size() - 1, percent);
}


size_t find_by_interpolation(const int what, const std::vector<int>& where, size_t from, size_t to) {
    if (where[from] == what)
        return from;
    if (where[to] == what)
        return to;
    double t = static_cast<double>(what - where[from]) / static_cast<double>(where[to] - where[from]);
    t = std::max(t, 0.);
    t = std::min(t, 1.);
    size_t mid = from + static_cast<size_t>((to - from) * t);
    if (mid == to || mid == from)
        return NONE;
    if (where[mid] < what)
        return find_by_interpolation(what, where, mid + 1, to);
    return find_by_interpolation(what, where, from, mid);
}

size_t find_by_interpolation(const int what, const std::vector<int>& where) {
    return find_by_interpolation(what, where, 0, where.size() - 1);
}


/*
function solved_linear(A, B, n){
    var X = [];
    for (var i = 0; i < n; ++i)
        X.push(0.0);

    // triangulize
    for (var i = 0; i < n-1; ++i)
        for (var j = 0; j < i+1; ++j) {
            r = A[i+1][j] / underflow_padded(A[j][j]);
            A[i+1][j] = 0.;
            for (var b_j = j+1; b_j < n; ++b_j){
                A[i+1][b_j] -= A[j][b_j]*r;
            }
            B[i+1] -= B[j]*r;
        }

    // calculate xs
    X[n-1] = B[n-1] / underflow_padded(A[n-1][n-1]);
    for (var i = n-2; i >= 0; --i){
        var s = 0.0;
        for (var j = i; j < n; ++j){
            s = s + A[i][j]*X[j];
        }
        X[i] = (B[i] - s) / underflow_padded(A[i][i]);
    }
    return X;
}

function approximation_of(points, n) {
    const N = points.length;
    var A = [];
    var B = [];

    for (var i = 0; i < n; ++i){
        var Ai = []
        for (var j = 0; j < n; ++j){
            Ai.push(0);
            for(var k = 0; k < N; ++k){
                Ai[j] += Math.pow(points[k][0], i + j);
            }
        }
        A.push(Ai);
        B.push(0);
        for(var k = 0; k < N; ++k){
            B[i] += points[k][1] * Math.pow(points[k][0], i);
        }
    }
    var P = solved_linear(A, B,n);
    return function(x) {
        var Px = 0;
        for(var i = 0; i < n; ++i) {
            Px += P[i] * Math.pow(x, i);
        }
        return Px;
    };
}
*/

std::vector solve(std::vector<std::vector<double>>& A, std::vector<double>& B) {
    const auto n = B.size();

    // triangulize
    for (auto i = 0u; i < n-1; ++i)
        for (auto j = 0u; j < i+1; ++j) {
            const auto r = A[i+1][j] / underflow_padded(A[j][j]);
            A[i+1][j] = 0.;
            for (auto b_j = j+1; b_j < n; ++b_j){
                A[i+1][b_j] -= A[j][b_j]*r;
            }
            B[i+1] -= B[j]*r;
        }

    // calculate xs
    std::vector<double> X(n, 0.);
    X[n-1] = B[n-1] / A[n-1][n-1];
    for (auto i = n-2; i >= 0; --i){
        var s = 0.0;
        for (auto j = i; j < n; ++j){
            s = s + A[i][j]*X[j];
        }
        X[i] = (B[i] - s) / A[i][i];
    }
    return X;
}

std::vector<double> polynomial_for(std::vector<int>& where, unsigned int n) {
    std::vector<std::vector<double>> A(n);
    for (auto& Ai : A)
        Ai.resize(n, 0.)
    std::vector<double> B(n, 0.);

    for (auto i = 0u; i < n; ++i){
        auto& Ai = A[i];
        for (auto j = 0u; j < n; ++j){
            for(auto k = 0u; k < N; ++k){
                Ai[j] += std::pow(points[k][0], i + j);
            }
        }

        for(auto k = 0u; k < N; ++k){
            B[i] += points[k][1] * std::pow(points[k][0], i);
        }
    }
    return solve(A, B, n);
}

double Px(std::vector<double> P, double x) {
    auto y = 0;
    for(auto i = 0u; i < n; ++i) {
        y += P[i] * std::pow(x, i);
    }
    return y;
}


