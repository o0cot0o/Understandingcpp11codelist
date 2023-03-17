/*
通常情况下，lambda函数的语法定义：
    [capture](parameters) mutable -> return-type{statement}

        [capture]: 捕捉列表。为lambda引出符，编译器通过此判断是否为lambda函数
        (parameters): 参数列表。无参可省略括号
        mutable: mutable修饰符。 默认情况下，lambda函数总是const函数，mutable可以取消其常量性，使用该修饰符时，参数类别不可省略
        -> return-type: 返回值类型。 用追踪返回值类型形式声明函数的返回类型。不需返回值时也可以连同->一起省略。
        {statement}: 函数体。
*/

int main() {
    int girls = 3, boys = 4;
    auto totalChild =[](int x, int y) -> int { return x + y; };
    return totalChild(girls, boys);
}