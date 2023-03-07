#include <cassert>
using namespace std;
#include <iostream>

// 枚举编译器对各种特性的支持 , 每个枚举值占一位 
// 在使用时可以通过 “或” 运算来压缩存储在整型变量中
enum FeatureSupports { 
    C99 = 0x0001, 
    ExtInt = 0x0002,
    SAssert = 0x0004,
    NoExcept = 0x0008, 
    SMAX = 0x0010, 
}; 

// 一个编译器类型，包括名称、特性支持等
struct Compiler{ 
    const char * name; 
    int spp; // 使用 FeatureSupports 枚举
}; 

int main() { 
    // 检查枚举值是否完备
    assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));
    //使用一个最大枚举 与所有其他枚举的或运算来验证是否有重复的枚举值

    Compiler a = {"abc", (C99 | SAssert)};  // (C99 | SAssert)表示Compiler a支持的特性
    // ... 
    if (a.spp & C99) {
        // 一些代码 ...
        cout << "a使用了C99特性" << endl; 
    } 
}