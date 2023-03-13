#include <vector>
using namespace std;

void fun(auto x = 1){}      // 1: quto函数参数，无法通过编译

struct str{
    auto var = 10;          // 2: auto非静态成员变量，无法通过编译
};

int main(){
    char x[3];
    auto y = x;
    auto z[3] = x;          // 3: auto数组，无法通过编译

    // 4: auto模板参数（实例化时），无法通过编译
    vector<auto> v = {1};
}

/*
auto不能推导：

    1、对于函数fun来说，auto不能是其形参类型。
    2、对于结构体来说，非静态成员变量的类型不能是auto。
    3、声明auto数组。
    4、在实例化模板的时候使用auto作为模板参数。

*/