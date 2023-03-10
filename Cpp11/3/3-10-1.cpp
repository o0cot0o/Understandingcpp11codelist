#include <iostream>
#include <type_traits>
using namespace std;

using uint = unsigned int;      // 使用using 命名别名
typedef unsigned int UINT;
using sint = int;

int main(){
    // 标准库 is_same模板类接收两个类型，value表示两个类型是否一致
    cout << is_same<uint, UINT>:: value << endl;  // 1
    
}