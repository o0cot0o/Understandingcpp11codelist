//定义宏NDEBUG禁用assert宏
#define NDEBUG

#include <cassert> 
using namespace std;

// 一个简单的堆内存数组分配函数
char * ArrayAlloc(int n) { 
    assert(n > 0); // 断言，n 必须大于 0 
    return new char [n]; 
}



int main (){
    char* a = ArrayAlloc(0); 
    // 违法返回
    //2-5-1: /workspace/Cpp11/2-5-1.cpp:6: char *ArrayAlloc(int): Assertion `n > 0' failed. 
    //Aborted (core dumped)
}

