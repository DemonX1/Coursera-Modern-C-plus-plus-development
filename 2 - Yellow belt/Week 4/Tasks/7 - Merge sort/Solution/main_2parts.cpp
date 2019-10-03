#include <vector>
#include <algorithm>
#include <iterator>

template < typename RandomIt >
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    std::vector < typename RandomIt::value_type > elements(range_begin, range_end);
    auto it = elements.begin() + elements.size() / 2;
    MergeSort(elements.begin(), it);
    MergeSort(it, elements.end());
    std::merge(elements.begin(), it, it, elements.end(), range_begin);
}