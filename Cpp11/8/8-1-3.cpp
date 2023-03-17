#include <iostream>
using namespace std;

// 自定义的ColorVector,拥有32字节的数据
struct alignas(32) ColorVector{
    double r;
    double g;
    double b;
    double a;
};

int main(){
    // 使用c++11中的alignof来查询ColorVector的对齐方式
    cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
    return 1;
}