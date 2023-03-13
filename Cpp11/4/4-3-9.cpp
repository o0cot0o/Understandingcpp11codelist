int i;
decltype(i) a;      // a : int
decltype((i)) b;    // b : int &, 无法通过编译

/*
decltype推导类型时，四规则
    1) 如果e是一个没有带括号的标记表达式或者类成员访问表达式，那么decltype(e)就是e所命名的实体的类型。
       如果e是一个被重载的函数，会导致编译时错误。
    2) 否则，假设e的类型为T,如果e是一个将亡值，那么decltype(e)为 T&&。 
    3) 否则，假设e的类型为T,如果e是一个左值，那么decltype(e)为 T&。
    4) 否则，假设e的类型为T,则decltype(e)为 T。 

*/