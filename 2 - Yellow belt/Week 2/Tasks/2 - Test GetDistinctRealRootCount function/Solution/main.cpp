#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

template < class T >
ostream &operator << (ostream &os, const vector < T > &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template < class T >
ostream &operator << (ostream &os, const set < T > &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template < class K , class V >
ostream &operator << (ostream &os, const map < K , V > &m) {
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template < class T , class U >
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template < class TestFunc >
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            throw 1;
        }
    }

private:
    int fail_count = 0;
};

int ReferenceGetRealRootCount(double a, double b, double c) {
    if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return 0; // just be it
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        if (b == 0) {
            if (c == 0) {
                return 1;
            } else {
                if (c < 0) {
                    return 2;
                } else {
                    return 0;
                }
            }
        } else {
            double d = b*b - 4*a*c;

            if (d < 0) {
                return 0;
            } else if (d == 0) {
                return 1;
            } else {
                return 2;
            }
        }
    }

    return -1;
}

int GetDistinctRealRootCount(double A, double B, double C) {
    return ReferenceGetRealRootCount(A, B, C);

    // найдём дискриминант
    double D = B * B - 4 * A * C;

    // если A равно нулю, то уравнение линейное: Bx + C = 0
    if (A == 0) {

        // Bx = -C => x = -C / B
        if (B != 0) {
            return 1;
            cout << -C / B << endl;
        }

        // если B равно нулю, корней нет
        return 0;
    } else if (D == 0) {  // случай с нулевым дискриминантом

        // корень ровно один
        return 1;

        cout << -B / (2 * A) << endl;
    } else if (D > 0) {  // в случае с положительным дискриминантом корня два

        double r1 = (-B + sqrt(D)) / (2 * A);
        double r2 = (-B - sqrt(D)) / (2 * A);

        return 2;

        cout << r1 << " " << r2 << endl;
    }

    // если дискриминант отрицателен, действительных корней нет
    return 0;
}

void TestConstantEquation() {
    AssertEqual(GetDistinctRealRootCount(0, 0, +1), 0, "0x^2 + 0x + 1 = 0 has 0 real roots");
    AssertEqual(GetDistinctRealRootCount(0, 0, -1), 0, "0x^2 + 0x - 1 = 0 has 0 real roots");
    AssertEqual(GetDistinctRealRootCount(0, 0,  0), 0, "0x^2 + 0x - 0 = 0 has inf real roots (but 0 is returned)");
}

void TestLinearEquation() {
    AssertEqual(GetDistinctRealRootCount(0, +1,  0), 1, "0x^2 + 1x + 0 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(0, -1,  0), 1, "0x^2 - 1x + 0 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(0, +1, +1), 1, "0x^2 + 1x + 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(0, +1, -1), 1, "0x^2 + 1x - 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(0, -1, +1), 1, "0x^2 - 1x + 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(0, -1, -1), 1, "0x^2 - 1x - 1 = 0 has 1 real roots");
}

void TestQuadricEquation() {
    AssertEqual(GetDistinctRealRootCount(+1,  0, +1), 0, " x^2 + 0x + 1 = 0 has 0 real roots");
    AssertEqual(GetDistinctRealRootCount(-1,  0, -1), 0, "-x^2 + 0x - 1 = 0 has 0 real roots");
    AssertEqual(GetDistinctRealRootCount(+1, +2, +3), 0, " x^2 + 2x + 3 = 0 has 0 real roots");
    AssertEqual(GetDistinctRealRootCount(-1, -2, -3), 0, "-x^2 - 2x - 3 = 0 has 0 real roots");

    AssertEqual(GetDistinctRealRootCount(+1, +2, +1), 1, " x^2 + 2x + 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(-1, -2, -1), 1, "-x^2 - 2x - 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(+1, -2, +1), 1, " x^2 - 2x + 1 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(-1, +2, -1), 1, "-x^2 + 2x - 1 = 0 has 1 real roots");

    AssertEqual(GetDistinctRealRootCount(+1,  0,  0), 1, " x^2 + 0x + 0 = 0 has 1 real roots");
    AssertEqual(GetDistinctRealRootCount(+1,  0, -1), 2, " x^2 + 0x - 1 = 0 has 2 real roots");
}

void TestRandomEquation() {
    default_random_engine generator;
    uniform_real_distribution < double > distribution(-100.0, 100.0);

    for (auto i = 0; i < 10000; ++i) {
        auto a = distribution(generator);
        auto b = distribution(generator);
        auto c = distribution(generator);

        auto real_roots = GetDistinctRealRootCount(a, b, c);
        auto reference_real_roots = ReferenceGetRealRootCount(a, b, c);

        Assert(real_roots >= 0 && real_roots <= 2, "Quadratic equation might have only 0, 1 or 2 real roots");
        AssertEqual(real_roots, reference_real_roots, "Equation " + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + " = 0 mist have " + to_string(reference_real_roots) + " roots");

        auto p = a + a;
        auto q = a * a;

        real_roots = GetDistinctRealRootCount(1, p, q);
        reference_real_roots = ReferenceGetRealRootCount(1, p, q);

        AssertEqual(real_roots, reference_real_roots, "Equation " + to_string(1) + "x^2 + " + to_string(p) + "x + " + to_string(q) + " = 0 mist have " + to_string(reference_real_roots) + " roots");
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(TestConstantEquation, "TestConstantEquation");
    runner.RunTest(TestLinearEquation  , "TestLinearEquation"  );
    runner.RunTest(TestQuadricEquation , "TestQuadricEquation" );
    runner.RunTest(TestRandomEquation  , "TestRandomEquation"  );

    return 0;
}
