#include <algorithm>
#include <iterator>

template < typename RandomIt >
std::pair < RandomIt, RandomIt > FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    return std::make_pair(
		std::lower_bound(range_begin, range_end, std::string {prefix}),
		std::upper_bound(range_begin, range_end, std::string {static_cast < char > (prefix + 1)})
	);
};
