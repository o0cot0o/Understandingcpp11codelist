template<typename ... Elements> class tuple;        // 变长模板的声明

template<typename Head, typename ... Tail>          // 递归的偏特化定义
class tuple<Head, Tail...>:private tuple<Tail...> { // 继承
    Head head;
};

template<> class tuple<> {};                    // 边界条件

/*
    使用递归的方式来进行变长模板的构造。

    当实例化一个 tuple<double, int, char, float>的类型时，引起基类的递归构造
    tupule<double, int, char, float> : private tuple<int, char, float>
    tuple<int, char, float> : private tuple<char, float>
    tuple<char, float> : private tuple<float>
    tuple<float> : private tuple<>                  调用边界构造

    实例化时构造顺序：tuple<> -> tuple<float> -> tuple<char, float> -> tuple<int, char, float> -> tupule<double, int, char, float>

*/