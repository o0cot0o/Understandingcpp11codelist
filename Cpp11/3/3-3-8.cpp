/*
    std::move_if_noexcept模板函数

    在类的移动构造函数没有 noexcept 关键字修饰时返回一个左值引用    变量可以使用拷贝语义

    在类的移动构造函数有 noexcept 关键字返回一个右值引用           变量可以使用移动语义
*/

#include <iostream> 
#include <utility> 
using namespace std; 
struct Maythrow { 
    Maythrow() {} 
    Maythrow(const Maythrow&) { 
        std::cout << "Maythorow copy constructor." << endl; 
    } 
    
    Maythrow(Maythrow&&) { 
        std::cout << "Maythorow move constructor." << endl; 
    } 
}; 

struct Nothrow { 
    Nothrow() {} Nothrow(Nothrow&&) noexcept { 
        std::cout << "Nothorow move constructor." << endl; 
    } 
    Nothrow(const Nothrow&) { 
        std::cout << "Nothorow move constructor." << endl; 
    } 
}; 

int main() { 
    Maythrow m; 
    Nothrow n; 
    Maythrow mt = move_if_noexcept(m); // move_if_noexcept返回左值，调用拷贝构造// Maythorow copy constructor. 
    Nothrow nt = move_if_noexcept(n); // move_if_noexcept返回右值，调用移动构造// Nothorow move constructor. 
    return 0; 
}