#include <iostream>
using namespace std;

int main(){
    int j = 12;
    auto by_val_lambda = [=]{ return j + 1; };
    auto by_ref_lambda = [&]{ return j + 1; };
    cout << "by_val_lambda: " << by_val_lambda() << endl;       // 13
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;       // 13

    j++;
    cout << "by_val_lambda: " << by_val_lambda() << endl;       // 13
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;       // 14
}

// 在by_val_lambda, j被视为一个常量，一旦初始化后不会再改变
// 在by_ref_lambda, j仍在使用父作用域中的值

// 如果需要捕捉的值成为lambda函数的常量， 通常使用按值传递的方式捕捉
// 如果需要捕捉的值成为lambda函数运行时的变量，则采用按引用方式进行捕捉