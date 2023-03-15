constexpr int f();
int a = f();
const int b = f();
// 在 a 和 b 的定义中，编译器将f()转换为一个函数调用
constexpr int c = f();          // 无法通过编译 
// 在 c 的定义中，由于是一个常量表达式，因此需要编译时的值，而f还没有定义，导致编译错误
constexpr int f() { return 1; }
constexpr int d = f();