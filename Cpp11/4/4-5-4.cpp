#include <iostream>
using namespace std;

int func(int a[]){
    for(auto e: a)          // 编译错误，作为参数传递而来的数组a范围不确定
        cout << e;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    func(arr);
}