int main(){
    double foo();
    auto x =1;          // x 的类型为int
    auto y =foo();      // y 的类型为double
    struct m {int i;}str;
    auto str1 = str;   // str1的类型是struct m

    auto z;         // 无法推导，无法通过编译
    z =x;           // auto声明的变量必须初始化
}