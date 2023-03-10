/*
    POD 好处
        1、字节赋值， 安全使用 memset 和 memcpy 对POD类型初始化和拷贝
        2、提供对C内存布局兼容
        3、保证了静态初始化的安全有效
*/

#include <type_traits>
#include <iostream>
using namespace std;

union U {};

union U1 { U1(){} }; // 不是平凡的

enum E{};

typedef double* DA;
typedef void (*PF)(int, double);

int main(){
    cout << is_pod<U>::value << endl;           // 1
    cout << is_pod<U1>::value << endl;          // 0
    cout << is_pod<E>::value << endl;           // 1
    cout << is_pod<int>::value << endl;         // 1
    cout << is_pod<DA>::value << endl;          // 1
    cout << is_pod<PF>::value << endl;          // 1
}