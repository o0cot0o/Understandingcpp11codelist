// struct A { 
//     A(int i) {} 
//     A(double d, int i) {}
//     A(float f, int i, const char* c) {} 
//     // ... 
// }; 

// struct B : A { 
//     B(int i): A(i) {} 
//     B(double d, int i) : A(d, i) {} 
//     B(float f, int i, const char* c) : A(f, i, c){} 
//     // ... 
//     virtual void ExtraInterface(){} 
// };

//使用 using

struct A { 
    A(int i) {} 
    A(double d, int i) {} 
    A(float f, int i, const char* c) {} 
    // ... 
}; 

struct B : A { 
    using A::A; // 继承构造函数
    int d{0};
    // ... 
    virtual void ExtraInterface(){} 
};

int main(){

    B b(356);  //b.d被初始化为 0
}