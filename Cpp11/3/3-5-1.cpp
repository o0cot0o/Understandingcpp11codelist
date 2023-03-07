#include <vector>
#include <map>

using namespace std;

int a[] = {1, 3, 5};            // c++98通过，c++11通过
int b[] = {2, 4, 6};            // c++98失败，c++11通过
vector<int> c{1, 3, 5};         // c++98失败，c++11通过
map<int, float> d = {{1, 1.0f}, {2, 2.0f}, {5, 3.2f}};  // c++98失败，c++11通过

/*
    变量初始化

    1、= + 赋值表达式               int a = 3 + 4
    2、= +花括号式的初始化列表       int a = {3 + 4}
    3、圆括号式的表达式列表          int a(3 + 4)       int * i = new int(1)
    4、花括号式的初始化列表          int a{3 + 4}       double * d = new double{1.2f}

*/