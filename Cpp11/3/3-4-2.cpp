#include <iostream>

using namespace std;

// 指针模板类型Ptr
template <typename T>
class Ptr{
public:
    Ptr(T* p):_p(p){} // 拷贝构造函数

    // 转换到bool类型
    operator bool() const{
        if(_p != 0)
            return true;
        else
            return false;
    }
private:
    T* _p;
};

int main(){
    int a;
    Ptr<int> p(&a);

    if(p)   // 自动转换为 bool 型, 没有问题
        cout << "valid pointer." << endl;   // valid pointer.
    else
        cout << "invalid pointer." << endl;

    Ptr<double> pd(0);

    cout << p + pd << endl;     // 1, 转换为bool类型相加,语义上没有意义 
}