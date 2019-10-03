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

template < typename T >
T Sqr(T x);

template < typename Item >
vector < Item > operator * (const vector < Item >& lhs, const vector < Item >& rhs);

template < typename First, typename Second>
pair < First, Second > operator * (const pair < First, Second >& lhs, const pair < First, Second >& rhs);

template < typename Key, typename Value>
map < Key, Value > operator * (const map < Key, Value >& lhs, const map < Key, Value >& rhs);

template < typename T >
T Sqr(T x) {
    return x * x;
}

template < typename Item >
vector < Item > operator * (const vector < Item >& lhs, const vector < Item >& rhs) {
    vector < Item > result(min(lhs.size(), rhs.size()));
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = lhs[i] * rhs[i];
    }
    return result;
}

template < typename First, typename Second>
pair < First, Second > operator * (const pair < First, Second >& lhs, const pair < First, Second >& rhs) {
    return make_pair(lhs.first * rhs.first, lhs.second * rhs.second);
}

template < typename Key, typename Value>
map < Key, Value > operator * (const map < Key, Value >& lhs, const map < Key, Value >& rhs) {
    map < Key, Value > result;

    for (const auto& item: lhs) {
        result[item.first] = item.second * rhs.at(item.first);
    }

    return result;
}
