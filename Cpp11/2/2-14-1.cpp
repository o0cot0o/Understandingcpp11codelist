// SFINEA - Substitution failure is not an error, 匹配失败不是错误
// 对重载的模板的参数进行展开时，如果展开导致了一些类型不匹配，编译器不会报错

// struct Test{
//     typedef int foo;
// };

// template <typename T>
// void f(typename T::foo) {}  //第一个模板定义 - #1

// template<typename T>        //第二个模板定义 - #2
// void f(T) {}

// int main(){
//     f<Test>(10);        // 调用 #1.
//     f<int>(10);         // 调用 #2. 由于SFINEA,虽然不存在类型int::foo,也不会发生编译错误
// }

// 标准提案
template <int I> struct A{};

char xxx(int);
char xxx(float);

template<class T> A<sizeof(xxx((T)0))> f(T){}

int main(){
    f(1);
}