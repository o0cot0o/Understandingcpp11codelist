/*
POD 标准布局

    1、所有非静态成员有相同的访问权限
    2、在类或结构体继承时，满足：
        派生类中有非静态成员，且只有一个仅包含静态成员的基类
        基类有非静态成员，而派生类没有非静态成员
    3、类中第一个非静态成员的类型与其基类不同
    4、没有虚函数和虚基类
    5、所有非静态数据成员均符合标准布局类型，其基类也符合标准布局

可使用模板类判断类型是否为标准布局
    template <typename T> struct std::is_standard_layout;


*/

#include <iostream>
using namespace std;

struct B1 {};
struct B2 {};

struct D1 : B1 {
    B1 b;       // 第一个非静态变量跟基类相同
    int i;
};

struct D2 : B1 {
    B2 b;
    int i;
};

int main(){
    D1 d1;
    D2 d2;
    cout << hex;
    cout << reinterpret_cast<long long> (&d1) << endl;
    // 7ffc400a1e68
    cout << reinterpret_cast<long long> (&(d1.b)) << endl;
    // 7ffc400a1e69
    //如果派生类的第一个成员仍然是基类，编译器会分配1字节的空间
    cout << reinterpret_cast<long long> (&(d1.i)) << endl;
    // 7ffc400a1e6c
    cout << reinterpret_cast<long long> (&d2) << endl;
    // 7ffc400a1e60
    cout << reinterpret_cast<long long> (&(d2.b)) << endl;
    // 7ffc400a1e60
    // d2和它的成员b共享一个地址
    // 如果基类没有成员，标准允许派生类的第一个成员与基类共享地址
    cout << reinterpret_cast<long long> (&(d2.i)) << endl;
    // 7ffc400a1e64
}