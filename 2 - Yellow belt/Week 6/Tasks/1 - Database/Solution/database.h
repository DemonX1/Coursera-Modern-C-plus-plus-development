#pragma once

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

#include "date.h"

using namespace std;

class Database {
public:
	void Add(const Date &date, const string &event);

	pair < Date, string > Last(const Date &date) const;
	void Print(ostream &os) const;

    template < class Func >
    int RemoveIf(Func predicate) {
        int result = 0;
        auto item = db.begin();
        while (item != db.end()) {
            auto event = stable_partition(item->second.begin(),
                                          item->second.end(),
                                          [&](const string str) {
                                            return !predicate(item->first, str);
                                          }
                                      );

            if (event != item->second.end()) {
                result += distance(event, item->second.end());
                item->second.erase(event, item->second.end());

                db_unique[item->first].clear();
                db_unique[item->first].insert(item->second.begin(), item->second.end());
            };

            if (item->second.empty()) {
                db_unique.erase(item->first);
                item = db.erase(item);
            } else {
                ++item;
            }
        }
        return result;
    }

    template < class Func >
    vector < pair < Date, string > > FindIf(Func predicate) const {
        vector < pair < Date, string > > result;

        auto item = db.begin();

        while (item != db.end()) {
            auto event = item->second.begin();

            while (event != item->second.end()) {
                event = find_if(event,
                                item->second.end(),
                                [&](const string &s) {
                                    return predicate(item->first, s);
                                }
                            );

                if (event != item->second.end()) {
                    result.emplace_back(make_pair(item->first, *event));
                    ++event;
                }
            }
            ++item;
        }

        return result;
    }

private:
	map < Date, vector < string > > db;
	map < Date, set < string > > db_unique;
};

string toString(const pair < Date, string > &record);

ostream &operator << (ostream &os, const pair < Date, string > &record);
