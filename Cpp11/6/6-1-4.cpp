// 对于自定义类型的数据，使其成为常量表达式值，定义自定义常量构造函数
// 常量表达式构造函数使用约束：
//      函数体必须为空
//      初始化列表只能由常量表达式来赋值
struct MyType{
    constexpr MyType(int x) : i(x) {}
    int i;
};
constexpr MyType mt = {0};