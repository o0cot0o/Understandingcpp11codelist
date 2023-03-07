#include <initializer_list> 
#include <vector>
#include <deque>
using namespace std;

// 函数的参数列表使用初始化列表
void Fun(initializer_list<int> iv){}

int main(){
    Fun({1, 2});
    Fun({});        //空列表
}

// 初始化列表用于函数返回, 列表初始化构造为返回类型的类型

vector<int> Func(){ return {1, 3}; }
deque<int> Func2(){ return {1, 3}; }

const vector<int>& Func1(){ return {3, 5}; } //返回引用类型必须要加const限制符，这里返回临时变量的引用。