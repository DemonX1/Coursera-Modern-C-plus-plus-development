#include <vector>
#include <algorithm>
#include <iterator>

template < typename RandomIt >
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 3) {
        return;
    }
    std::vector < typename RandomIt::value_type > elements(range_begin, range_end);
    auto it1 = elements.begin() + elements.size() / 3;
    auto it2 = it1 + elements.size() / 3;

    MergeSort(elements.begin(), it1);
    MergeSort(it1, it2);
    MergeSort(it2, elements.end());

    std::vector < typename RandomIt::value_type > tmp;

    std::merge(elements.begin(), it1, it1, it2, std::back_inserter(tmp));
    std::merge(tmp.begin(), tmp.end(), it2, elements.end(), range_begin);
}
