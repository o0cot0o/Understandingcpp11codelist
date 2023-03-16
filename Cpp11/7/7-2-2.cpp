#include <type_traits>
#include <iostream>
using namespace std;

class TwoCstor {
    // 提供了带参数版本的构造函数，再指示编译器
    // 提供默认版本，则本自定义类型依然是POD类型
    TwoCstor() = default;
    TwoCstor(int i) : data(i) {}
private:
    int data;
};

int main(){
    cout << is_pod<TwoCstor>::value << endl;       // 1
}