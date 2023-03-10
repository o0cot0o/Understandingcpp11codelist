#include <iostream> 
using namespace std; 
class HasPtrMem { 
    public: 
    HasPtrMem(): d(new int(0)) { cout << "Construct: " << ++n_cstr << endl; } 
    HasPtrMem(const HasPtrMem & h): d(new int(*h.d)) { cout << "Copy construct: " << ++n_cptr << endl; } 
    ~HasPtrMem() { cout << "Destruct: " << ++n_dstr << endl; }
    int * d; 
    static int n_cstr; 
    static int n_dstr; 
    static int n_cptr; 
}; 

int HasPtrMem::n_cstr = 0; 
int HasPtrMem::n_dstr = 0; 
int HasPtrMem::n_cptr = 0; 
HasPtrMem GetTemp() { return HasPtrMem(); } 

int main() { 
    HasPtrMem a = GetTemp();
}

//g++ 3-3-3.cpp -fno-elide-constructors                       
// 输出                             
// Construct: 1                     
// Copy construct: 1                
// Destruct: 1                      
// Copy construct: 2
// Destruct: 2
// Destruct: 3

// -fno-elide-constructors 关闭了 Return Value Optimization 
// 直接运行
// 输出
// Construct: 1
// Destruct: 1
// a直接占用GetTemp()返回值

