#include <algorithm>
#include <vector>
#include <iterator>

template < class T >
void RemoveDuplicates(std::vector < T > &elements) {
    std::sort(elements.begin(), elements.end());

    elements.erase(std::unique(elements.begin(), elements.end()), elements.end());

    return;
}