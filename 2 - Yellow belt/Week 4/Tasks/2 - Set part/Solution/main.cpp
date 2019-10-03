#include <vector>
#include <set>
#include <algorithm>

template < class T >
std::vector < T > FindGreaterElements(const std::set < T > &elements, const T &border) {
    return {std::upper_bound(elements.begin(), elements.end(), border), elements.end()};
}
