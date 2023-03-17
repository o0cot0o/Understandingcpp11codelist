#include <iostream>
#include <memory>
using namespace std;

struct alignas(alignof(double)*4) ColorVector{
    double r;
    double g;
    double b;
    double a;
};

// 固定容量的模板函数
template <typename T>
class FixedCapacityArray {
public:
    void push_back(T t){ /* 在data中加入t变量 */}
    // ...
    // 一些其他成员函数、成员变量
    // ...
    char alignas(T) data[1024] = {0};           // error: 'alignas' attribute cannot be applied to types
    // int length = 1024 / sizeof(T);
};

int main(){
    FixedCapacityArray<char> arrCh;
    cout << "alignof(char): " << alignof(char) << endl;
    cout << "alignof(arrCh.data): " << alignof(arrCh.data) << endl;

    FixedCapacityArray<ColorVector> arrCV;
    cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
    cout << "alignof(arrCV.data): " << alignof(arrCV.data) << endl;
    return 1;
}