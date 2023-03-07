template <typename T> struct MyTemplate { }; 
//通过取别名的方式
typedef struct { int a; }b;

int main() { 
    // MyTemplate<struct { int a; }> t; // 无法编译通过 , 匿名类型的声明不能在模板实参位置return 0; 
    MyTemplate<b> t;
}