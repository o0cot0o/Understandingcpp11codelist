#include <iostream>
using namespace std;

struct Date {
    constexpr Date(int y, int m, int d):
        year(y), month(m), day(d) {}
    
    constexpr int GetYear() { return year; }
    constexpr int GetMonth() { return month; }
    constexpr int GetDay() { return day; }

private:
    int year;
    int month;
    int day;
};

constexpr Date PRCfound{1949, 10, 1};
constexpr int foundmonth = PRCfound.GetMonth();     // c++17编译错误
// error: 'this' argument to member function 'GetMonth' has type 'const Date', but function is not marked const

int main(){ cout << foundmonth << endl;}    // 10

// g++ -std=c++11 6-1-5.cpp