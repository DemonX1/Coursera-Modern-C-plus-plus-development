#include <algorithm>
#include <string>
#include <iterator>

template < typename RandomIt >
std::pair < RandomIt, RandomIt > FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string &prefix) {
    return std::equal_range(range_begin, range_end, prefix, 
		[&prefix](const std::string &a, const std::string &b) {
			return a.compare(0, prefix.length(), b.substr(0, prefix.length())) < 0;
		}
	);
};