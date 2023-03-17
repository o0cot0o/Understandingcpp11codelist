/*
    捕捉类别[capture]有多个捕捉向组成，以逗号分割。
        [var]表示值传递方式捕捉变量var
        [=] 表示值传递方式捕捉所有父作用域的变量（包括this）
        [&var] 表示引用传递捕捉变量var
        [&] 表示引用传递捕捉所有父作用域的变量（包括this）
        [this] 表示值传递的方式捕捉当前的this指针
    通过一些组合，捕捉类别可以表示更复杂的意思
        [=,&a,&b]表示以引用传递的方式捕捉变量a和b,值传递的方式捕捉其他变量
        [&,a,this]表示以值传递的方式捕捉变量a和this，引用传递方式捕捉其他所有变量。
    重复导致编译期错误
        [=,a]   =已经以值传递方式捕捉了所有变量
        [&, &this]  &已经以引用传递方式捕捉了所有变量
*/

int main() {
    int boys = 4, girls = 3;
    auto totalChild = [girls, &boys]() -> int { return girls + boys; };
    return totalChild();
}