#pragma once

#include <iostream>
#include <iomanip>
#include <tuple>

using namespace std;

struct Day {
	Day(int d) :
	    value(d) {

    }

	int value;
};

struct Month {
	Month(int m) :
	    value(m) {

    }

	int value;
};

struct Year {
	Year(int y) :
	    value(y) {

    }

	int value;
};

class Date {
public:
	Date(Year y = 0, Month m = 0, Day d = 0) :
	    year(y),
	    month(m),
	    day(d) {

    }

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	Year year;
	Month month;
	Day day;
};

bool operator == (const Date &lhs, const Date &rhs);
bool operator != (const Date &lhs, const Date &rhs);
bool operator <  (const Date &lhs, const Date &rhs);
bool operator >  (const Date &lhs, const Date &rhs);
bool operator <= (const Date &lhs, const Date &rhs);
bool operator >= (const Date &lhs, const Date &rhs);

ostream &operator << (ostream &os, const Date &date);

Date ParseDate(istream &is);
