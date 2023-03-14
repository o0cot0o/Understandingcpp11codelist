// declare_reachable 和 undeclare_reachable只是确立了一个范围，
// 即在两者之间的代码运行中，p所指对象不会被垃圾回收器所回收

#include <memory>
int main(){
    int *p = new int;

    std::declare_reachable(p);          // 在p被隐藏之前声明为可达的

    int *q = (int*)(reinterpret_cast<long long>(p) ^ 2012);     // q隐藏了p

    // 解除可达声明
    q = std::undeclare_reachable<int>((int*)((long long)q ^ 2012));

    // 做一些其他工作，垃圾回收器可能已经回收了p指向对象
    q = (int*)(reinterpret_cast<long long>(q) ^ 2012);      // 使用可逆的异或运算重新获得p的地址，这里的 q == p
    *q = 10;
}