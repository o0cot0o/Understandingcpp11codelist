/* 
用auto来声明多个变量时，只有第一个变量用于auto的类型推导，
然后推导出来的数据类型被作用于其他的变量。

*/

auto x = 1, y = 2;          // x和y的类型均为int

// m是一个指向const int 类型变量的指针，n是一个int类型的变量
const auto * m = &x, n = 1;

auto i = 1, j = 3.14f;      // 编译失败

auto o = 1, &p = o, *q = &p;// 从左向右推导