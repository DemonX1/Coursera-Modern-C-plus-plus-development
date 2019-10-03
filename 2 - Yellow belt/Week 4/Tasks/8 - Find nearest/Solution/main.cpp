#include <iterator>
#include <set>
#include <algorithm>

std::set < int >::const_iterator FindNearestElement(const std::set < int > &numbers, int border) {
    auto nearest = numbers.lower_bound(border);
    if (nearest != std::begin(numbers)) {
        if (abs(*nearest - border) >= abs(border - *std::prev(nearest))) {
            return std::prev(nearest);
        }
    }
    return nearest;
}
