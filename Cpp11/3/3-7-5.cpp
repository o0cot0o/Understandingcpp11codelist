#include <string>
using namespace std;


union T {
    string s;
    int n;
public:
    // 自定义构造函数和析构函数
    T(){ new (&s) string; };        // 采用placement new 将s构造在地址&s上
    ~T(){ s.~string(); } 
};

int main(){
    T t;        //构造析构成功
}