#include <iostream> 
using namespace std; 

// 定义一个函数模板
template <typename T> 
void TempFun(T a) { 
    cout << a << endl; 
} 

void DefParm(int m = 3) {} // c++98 编译通过，c++11 编译通过
template <typename T = int> class DefClass {}; // c++98 编译通过，c++11 编译通过
template <typename T = int> void DefTempParm() {}; // c++98 编译失败，c++11 编译通过

int main() { 
    TempFun(1); // 1, ( 实例化为 TempFun<const int>(1)) 
    TempFun("1"); // 1, ( 实例化为 TempFun<const char *>("1")) 
}