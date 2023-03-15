// 使用constexpr来将函数变为常量表达式， 得到编译时常量
/*
    常量表达式函数要求
        函数体只有单一的return返回语句
        函数必须返回值（不能是void函数）
        在使用前必须已有定义
        return返回语句表达式中不能使用非常量表达式的函数、全局数据，且必须是一个常量表达式
*/
constexpr int GetConst() { return 1; }

void Constless(int cond){
    int arr[GetConst()] = {0};      // 无法通过编译

    enum { e1 = GetConst(), e2};    // 无法通过编译

    switch (cond) {
        case GetConst():            // 无法通过编译
            break;
        default:
            break;
    }
}