#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cassert>

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

template <class T>
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
ostream& operator << (ostream &os, const map < K , V > &m) {
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
void AssertEqual(const T &t, const U &u, const string &hint = {}, const string &func_name = {}, const string &file_name = {}, const string &line = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " in funcion " << func_name << " from file " << file_name << " in line " << line;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint, const string &func_name = {}, const string &file_name = {}, const string &line = {}) {
    AssertEqual(b, true, hint, func_name, file_name, line);
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
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

/*
bool IsPalindrom(const string &s) {
    auto s1 = s;
    reverse(s1.begin(), s1.end());

    return (s != s1);
}
*/

void TestIsPalindrom() {
    Assert(IsPalindrom(""), "empty string is a palindrome", __func__, __FILE__, to_string(__LINE__));
    Assert(IsPalindrom("a"), "one letter string is a palindrome");
    Assert(IsPalindrom("aba"), "aba is a palindrome");
    Assert(IsPalindrom("abba"), "abba is a palindrome");
    Assert(IsPalindrom("abacaba"), "abacaba is a palindrome");
    Assert(IsPalindrom("a  b  a"), "`a b a` is a palindrome");
    Assert(IsPalindrom("a  bb  a"), "`a bb a` is a palindrome");
    Assert(IsPalindrom("   a   "), "`   a   ` is a palindrome");
    Assert(IsPalindrom("   aa   "), "`   aa   ` is a palindrome");

    Assert(!IsPalindrom("aba   "), "`aba   ` is not a palindrome");
    Assert(!IsPalindrom("abba   "), "`abba   ` is not a palindrome");
    Assert(!IsPalindrom("   aba"), "`   aba` is not a palindrome");
    Assert(!IsPalindrom("   abba"), "`   abba` is not a palindrome");

    Assert(!IsPalindrom("ab"), "ab is not a palindrome");
    Assert(!IsPalindrom("abac"), "abac is not a palindrome");
    Assert(!IsPalindrom("caba"), "caba is not a palindrome");
    Assert(!IsPalindrom("abca"), "abca is not a palindrome");
    Assert(!IsPalindrom("cabar"), "cabar is not a palindrome");
    Assert(!IsPalindrom("carbac"), "carbac is not a palindrome");
    Assert(!IsPalindrom("abaqw rcc wqaba"), "abaqwrccwqaba is not a palindrome");

    Assert(!IsPalindrom("was it a car or a cat i saw"), "`was it a car or a cat i saw` is not a palindrome because spaces do not match");

}

int main() {
    TestRunner runner;
    runner.RunTest(TestIsPalindrom, "TestIsPalindrom");

//    cout << __LINE__ << " of " << __func__ << " of " << __FILE__ << endl;

    return 0;
}
