#include <iostream> 
using namespace std; 
class Moveable{ 
public: 
    Moveable():i(new int(3)) {} 
    ~Moveable() { delete i; } 
    Moveable(const Moveable & m): i(new int(*m.i)) { } 
    Moveable(Moveable && m):i(m.i) { m.i = nullptr; } 
    int* i; 
}; 

int main() { 
    Moveable a;     // 左值
    // move(a) -> 右值引用
    Moveable c(move(a)); // 会调用移动构造函数， 调用过程中a.i被置为 nullptr
    cout << *a.i << endl; // 运行时错误
}