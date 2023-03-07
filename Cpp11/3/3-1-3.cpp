#include <iostream> 
using namespace std; 

struct Base { 
    void f(double i){ cout << "Base:" << i << endl; } 
}; 

struct Derived : Base { 
    using Base::f;      //如果派生类要使用基类的成员函数的话，可以通过 using 声明
    void f(int i) { cout << "Derived:" << i << endl; } 
}; 
    
int main() { 
    Base b; 
    b.f(4.5); // Base:4.5 

    Derived d; 
    d.f(4.5); // Base:4.5 
    
}