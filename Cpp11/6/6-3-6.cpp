#include <thread>
#include <atomic>
#include <iostream>
using namespace std;

atomic<int> a {0};
atomic<int> b {0};

int ValueSet(int) {
    int t = 1;
    a.store(t, memory_order_relaxed);       // 枚举值 memory_order_relaxed 
    b.store(2, memory_order_relaxed);       // 表示使用松散的内存模型，任由编译器重排序或者由处理器乱序执行
}

int Observer(int){
    cout << "(" << a << ", " << b << ")" << endl;       // 可能有多种输出
}

int main() {
    thread t1(ValueSet, 0);
    thread t2(Observer, 0);

    t1.join();
    t2.join();
    cout << "Got (" << a << ", " << b << ")" << endl;   //Got(1, 2) 
}