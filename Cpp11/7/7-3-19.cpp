int d = 0;
int TryCapture(){
    auto ill_lambda = [d]{};        // 编译错误，不能捕捉到d
}