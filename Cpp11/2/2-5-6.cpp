int positive(const int n) { 
    // static_assert 的断言表达式的结果必须是在编译时期可以计算的表达式，
    // 即必须是常量表达式
    static_assert(n > 0, "value must >0");
    // error: ‘n’ is not a constant expression
}