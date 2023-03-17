void DoSomething1();
void DoSomething2();

[[noreturn]] void ThrowAway(){      // [[noreturn]]的函数在调用完后，后续代码不会被执行
    throw "expection";      // 控制流跳转到异常处理
}

void Func(){
    DoSomething1();
    ThrowAway();
    DoSomething2();         // 该函数不可到达
}
