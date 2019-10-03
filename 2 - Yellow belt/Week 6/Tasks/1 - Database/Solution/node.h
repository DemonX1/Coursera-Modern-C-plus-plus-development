#pragma once

#include <string>
#include <exception>
#include <memory>

#include "date.h"
#include "token.h"

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And
};

class Node {
public:
	virtual bool Evaluate(const Date &date, const string &event) const = 0;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date &date, const string &event) const override {
        return true;
	}
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison &operation, const Date &date) :
	    _operation(operation),
	    _date(date) {

    }

	bool Evaluate(const Date &date, const string &event) const override {
        if (_operation == Comparison::Equal) {
            return date == _date;
        } else if (_operation == Comparison::NotEqual) {
            return date != _date;
        } else if (_operation == Comparison::Less) {
            return date < _date;
        } else if (_operation == Comparison::LessOrEqual) {
            return date <= _date;
        } else if (_operation == Comparison::Greater) {
            return date > _date;
        } else if (_operation == Comparison::GreaterOrEqual) {
            return date >= _date;
        } else {
            throw invalid_argument("Invalid argument in DateComparisonNode");
        }
	}

private:
	const Comparison _operation;
	const Date _date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison &operation, const string &event) :
	    _operation(operation),
	    _event(event) {

    }

	bool Evaluate(const Date &date, const string &event) const override {
        if (_operation == Comparison::Equal) {
            return event == _event;
        } else if (_operation == Comparison::NotEqual) {
            return event != _event;
        } else if (_operation == Comparison::Less) {
//            throw invalid_argument("Invalid argument (less) in EventComparisonNode");

            return event < _event;
        } else if (_operation == Comparison::LessOrEqual) {
//            throw invalid_argument("Invalid argument (less or equal) in EventComparisonNode");

            return event <= _event;
        } else if (_operation == Comparison::Greater) {
//            throw invalid_argument("Invalid argument (greater) in EventComparisonNode");

            return event > _event;
        } else if (_operation == Comparison::GreaterOrEqual) {
 //           throw invalid_argument("Invalid argument (greater or equal) in EventComparisonNode");

            return event >= _event;
        } else {
            throw invalid_argument("Invalid argument (not in enum) in EventComparisonNode");
        }
    }

private:
	const Comparison _operation;
	const string _event;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation operation, shared_ptr < Node > left, shared_ptr < Node > right) :
		_operation(operation),
		_left(left),
		_right(right) {

    }

	bool Evaluate(const Date &date, const string &event) const override {
        if (_operation == LogicalOperation::And) {
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
        } else if (_operation == LogicalOperation::Or) {
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
        } else {
            throw invalid_argument("Invalid argument in LogicalOperationNode");
        }
    }

private:
	LogicalOperation _operation;
	shared_ptr < Node > _left;
	shared_ptr < Node > _right;
};
