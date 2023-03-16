#include <cstddef>
#include <new>

extern void* p;

class NoStackAlloc {
public:
    ~NoStackAlloc() = delete;
};

int main(){
    NoStackAlloc nsa;           // 无法通过编译
    new (p) NoStackAlloc();     // placement new, 假设p无需调用析构函数
    return 1;
}