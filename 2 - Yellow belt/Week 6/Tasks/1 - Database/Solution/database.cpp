#include "database.h"

void Database::Add(const Date &date, const string &event) {
	if (db.count(date) == 0) {
		db[date].push_back(event);
		db_unique[date].insert(event);
	} else {
		if (db_unique[date].count(event) == 0) {
            db[date].push_back(event);
            db_unique[date].insert(event);
		}
	}

	return;
}

pair < Date, string > Database::Last(const Date &date) const {
	auto it = db.upper_bound(date);
	if (it == db.begin()) {
        throw invalid_argument("date@Last is less than first date");
	} else {
        --it;
        return {it->first, db.at(it->first).back()};
	}
}

void Database::Print(ostream &os) const {
	os << setfill('0');
	for (const auto &record : db) {
		for (const auto &event : record.second) {
			os << setw(4) << record.first.GetYear() << "-"
               << setw(2) << record.first.GetMonth() << "-"
               << setw(2) << record.first.GetDay() << " " << event << endl;
		}
	}

	return;
}

string toString(const pair < Date, string > &record) {
    stringstream s;
    s << record.first << " " << record.second;

    return s.str();
}

ostream &operator << (ostream &os, const pair < Date, string > &record) {
    return os << record.first << " " << record.second;
}
