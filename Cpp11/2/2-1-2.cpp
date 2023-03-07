#include <string>
#include <iostream> 
using namespace std; 

const char* hello() { 
    // 隐式地在函数定义之后定义__func__标识符
    // static const char* __func__ = "hello";
    return __func__; 
} 

const char* world() { 
    return __func__; 
} 

int main(){ 
    cout << hello() << ", " << world() << endl; // hello, world 
}