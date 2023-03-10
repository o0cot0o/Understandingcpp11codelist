#include <iostream>
using namespace std;

// 当非受限联合体有一个非POD成员时，并且这个非POD成员有非平凡的构造函数
// 非受限联合体的默认构造函数将被编译器删除，默认拷贝构造函数、拷贝赋值操作符和析构函数也被删除。
union T {
    string s;       // string有非平凡的构造函数
    int n;
};

int main() {
    T t;            // 构造失败，因为T的构造函数被删除了
}

// g++ -std=c++11 3-7-4.cpp