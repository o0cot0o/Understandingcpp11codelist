// #pragma once
// _Pragma("once");

#include <iostream>
using namespace std; 

struct TestStruct {
    //可以在构造函数的初始化成员列表中使用
    TestStruct () : name(__func__) {}
    const char *name;
}; 
// 不能将 __fun__ 标识符作为函数参数的默认值
// void FuncFail( string func_name = __func__) {};// 无法通过编译

int main() { 

    TestStruct ts;
    cout << ts.name << endl; // TestStruct 
}