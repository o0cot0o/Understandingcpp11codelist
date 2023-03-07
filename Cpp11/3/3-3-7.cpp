/*为了保证移动语义的传递，程序员在编写移动构造函数的时候，
应该总是记得使用 std::move 转换拥有形如堆内存、文件句柄等资源的成员为右值 */

/*
    标准库的头文件 <type_traits>

    判断一个类型是否是可以移动的

    is_move_constructible
    is_trivially_move_constructible
    is_nothrow_ move_constructible

    使用方法：
    cout << is_move_constructible<UnknownType>::value;
*/

#include <iostream> 
using namespace std; 
class HugeMem{ 
public: 
    HugeMem(int size): sz(size > 0 ? size : 1) { 
        c = new int[sz]; 
    } 
    ~HugeMem() { delete [] c; } 
    HugeMem(HugeMem && hm): sz(hm.sz), c(hm.c) { // 移动语义
        hm.c = nullptr;  //只将指针置空
    } 
    int * c; 
    int sz; 
}; 

class Moveable{ 
    public: 
    Moveable():i(new int(3)), h(1024) {} 
    ~Moveable() { delete i; } 
    Moveable(Moveable && m): 
        i(m.i), h(move(m.h)) { // 强制转为右值，以调用HugeMem移动构造函数
        // m 将在表达式结束后被析构，其成员h也自然会被析构
        m.i = nullptr; 
    } 
    int* i; 
    HugeMem h; 
}; 
Moveable GetTemp() { 
    Moveable tmp = Moveable();  // 构造函数 tmp{i->3, h=HugeMen{c->int[1024], sz=1024}}
    cout << hex << "Huge Mem from " << __func__ << " @" << tmp.h.c << endl; // Huge Mem from GetTemp @0x603030 
    return tmp; 
} 
int main() { 
    Moveable a(GetTemp()); // 调用Moveable移动构造函数 右值为 Moveable{i->3, h=HugeMen{c->int[1024], sz=1024}}
    cout << hex << "Huge Mem from " << __func__ << " @" << a.h.c << endl; // Huge Mem from main @0x603030 
}