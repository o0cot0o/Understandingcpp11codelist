/*标准库中 <type_traits> 头文件提供模板类

    is_rvalue_ reference
    is_lvalue_reference
    is_reference

    判断引用类型
*/
#include <iostream> 
using namespace std; 

struct Copyable { 
    Copyable() {} 
    Copyable(const Copyable &o) { 
        cout << "Copied" << endl; 
    } 
}; 

Copyable ReturnRvalue() { return Copyable(); } 

// 值传递，     左值
void AcceptVal(Copyable) {} 

// 引用传递，   常量左值引用
void AcceptRef(const Copyable & ) {} 

//                   右值引用
void AcceptRvalueRef(Copyable && s) {
    Copyable news = std::move(s);   //需要实现以右值引用为参数的移动构造函数，否则调用以常量左值引用为参数的拷贝构造函数
    // std::move：强制转化为右值
    // 被转化的左值，不改变其生命期
}

template<class T>
const T && crvalueref = ReturnRvalue(); // 常量右值引用， 暂无用途

int main() { 
    cout << "Pass by value: " << endl; 
    AcceptVal(ReturnRvalue()); // 临时值被拷贝传入
    cout << "Pass by reference: " << endl; 
    AcceptRef(ReturnRvalue()); // 临时值被作为引用传递

}