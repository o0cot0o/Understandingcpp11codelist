int foo(){
    int* px = (void*)0;     // 编译错误，不能隐式地将无类型指针转换为int*类型的指针

    int* py = nullptr;
}