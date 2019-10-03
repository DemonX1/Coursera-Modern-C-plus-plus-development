#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <utility>
#include <exception>
#include <stdexcept>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

template < typename Key, typename Value >
Value& GetRefStrict(map < Key, Value >& input_map, Key key) {
    if (input_map.count(key) == 0) {
        throw runtime_error("no such key in dictionary");
    }
    return input_map[key];
}
