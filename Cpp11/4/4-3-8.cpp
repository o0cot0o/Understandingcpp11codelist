#include <iostream>
#include <type_traits>
using namespace std;

typedef double (*func)();

int main(){
    // result_of 是基于decltype的模板类
    /*
    template<class>
    struct result_of;

    template<class F, class... ArgTypes>
    struct result_of<F(ArgTypes...)>{
        typedef decltype(
                        std::declval<F>()(std::declval<ArgTypes>()...)
                        )type;
    };
    */
    // 用于推导函数的返回类型
    result_of<func()>::type f;      // 由func() 推导其结果类型

    cout << typeid(f).name() << endl;
}