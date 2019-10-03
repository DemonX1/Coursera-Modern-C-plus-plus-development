#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

class Figure {
public:
    virtual std::string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const int &new_a, const int &new_b, const int &new_c)
        : perimeter(new_a + new_b + new_c),
          area(sqrt(perimeter / 2. * (perimeter / 2. - new_a) *
                                     (perimeter / 2. - new_b) *
                                     (perimeter / 2. - new_c)
                    )
               ) {

    }

    virtual std::string Name() const {
        return "TRIANGLE";
    }

    virtual double Perimeter() const {
        return perimeter;
    }

    virtual double Area() const {
        return area;
    }

protected:
    const double perimeter;
    const double area;
};

class Rect : public Figure {
public:
    Rect(const int &new_a, const int &new_b)
        : perimeter(2*new_a + 2*new_b),
          area(new_a*new_b) {

    }

    virtual std::string Name() const {
        return "RECT";
    }

    virtual double Perimeter() const {
        return perimeter;
    }

    virtual double Area() const {
        return area;
    }

protected:
    const double perimeter;
    const double area;
};

class Circle : public Figure {
public:
    Circle(const int &new_r)
        : perimeter(2 * 3.14 * new_r),
          area(3.14 * new_r * new_r) {

    }

    virtual std::string Name() const {
        return "CIRCLE";
    }

    virtual double Perimeter() const {
        return perimeter;
    }

    virtual double Area() const {
        return area;
    }

protected:
    const double perimeter;
    const double area;
};

std::shared_ptr < Figure > CreateFigure(std::istream& input_stream) {
    std::string type;
    input_stream >> type;
    if (type == "TRIANGLE") {
        int a, b, c;
        input_stream >> a >> b >> c;
        return std::make_shared < Triangle > (a, b, c);
    } else if (type == "RECT") {
        int a, b;
        input_stream >> a >> b;
        return std::make_shared < Rect > (a, b);
    } else {
        int r;
        input_stream >> r;
        return std::make_shared < Circle >(r);
    }
}
