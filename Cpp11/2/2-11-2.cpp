//为类模板的多个默认模板参数声明指定默认值的时候，必须遵照 "从右往左"的规则进行指定

template<typename T1, typename T2 = int> class DefClass1; 
template<typename T1 = int, typename T2> class DefClass2; // 无法通过编译

template<typename T, int i = 0> class DefClass3; 
template<int i = 0, typename T> class DefClass4; // 无法通过编译


// 对函数模板来说并不是必须的
template<typename T1 = int, typename T2> void DefFunc1(T1 a, T2 b); 
template<int i = 0, typename T> void DefFunc2(T a);