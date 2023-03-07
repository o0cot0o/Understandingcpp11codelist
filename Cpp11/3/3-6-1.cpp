/*
POD: Plain Old Data, 划分为平凡的和标准布局的

平凡的：
    1、拥有平凡的默认构造函数和析构函数
    2、拥有平凡的拷贝构造函数和移动构造函数
    3、拥有平凡的拷贝赋值运算符和移动赋值运算符
    4、不能包含虚函数以及虚基类


使用类模板判断是否平凡
template <typename T> struct std::is_trivial;
*/

#include <iostream>
#include <type_traits>
using namespace std;

struct Trivial1{};
struct Trivial2{
public:
    int a;
private:
    int b;
};

struct Trivial3{
    Trivial1 a;
    Trivial2 b;
};


struct Trivial4{
    Trivial2 a[23];
};


struct Trivial5{
    int x;
    static int y;
};


struct NonTrivial1{
    NonTrivial1() : z(42) {}
    int z;
};

struct NonTrivial2{
    NonTrivial2();
    int w;
};
NonTrivial2::NonTrivial2() = default;

struct NonTrivial3{
    Trivial5 c;
    virtual void f();
};

int main(){
    cout << is_trivial<Trivial1>::value << endl;        // 1
    cout << is_trivial<Trivial2>::value << endl;        // 1
    cout << is_trivial<Trivial3>::value << endl;        // 1
    cout << is_trivial<Trivial4>::value << endl;        // 1
    cout << is_trivial<Trivial5>::value << endl;        // 1
    cout << is_trivial<NonTrivial1>::value << endl;     // 0
    cout << is_trivial<NonTrivial2>::value << endl;     // 0
    cout << is_trivial<NonTrivial3>::value << endl;     // 0
    return 0;
}