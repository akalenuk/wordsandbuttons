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

