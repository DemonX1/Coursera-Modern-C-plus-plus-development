#include <iostream>
#include <deque>

enum class Operator {
    Add,
    Sub,
    Mul,
    Div
};

struct Operation {
    Operator type;
    std::string value;
};

std::istream& operator >> (std::istream &is, Operation &operation) {
    std::string operatorString;
    is >> operatorString;
    if (operatorString == "+") {
        operation.type = Operator::Add;
        is >> operation.value;
    } else if (operatorString == "-") {
        operation.type = Operator::Sub;
        is >> operation.value;
    } else if (operatorString == "*") {
        operation.type = Operator::Mul;
        is >> operation.value;
    } else if (operatorString == "/") {
        operation.type = Operator::Div;
        is >> operation.value;
    }

    return is;
}

int main() {
    int x, n;
    std::cin >> x >> n;

    Operation operation;
    Operation last_operation;

    std::deque < std::string > result;
    result.push_back(std::to_string(x));

    for (int i = 0; i < n; ++i) {
        std::cin >> operation;

        switch (operation.type) {
            case Operator::Add:
                result.push_back("+");
                result.push_back(operation.value);
                break;
            case Operator::Sub:
                result.push_back("-");
                result.push_back(operation.value);
                break;
            case Operator::Mul:
                if (last_operation.type == Operator::Add || last_operation.type == Operator::Sub) {
                    result.push_front("(");
                    result.push_back(")");
                }
                result.push_back("*");
                result.push_back(operation.value);
                break;
            case Operator::Div:
                if (last_operation.type == Operator::Add || last_operation.type == Operator::Sub) {
                    result.push_front("(");
                    result.push_back(")");
                }
                result.push_back("/");
                result.push_back(operation.value);
                break;
        }

        last_operation = operation;
    }

    for (const auto &item : result) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            std::cout << " " << item << " ";
        } else {
            std::cout << item;
        }
    }

    return 0;
}
