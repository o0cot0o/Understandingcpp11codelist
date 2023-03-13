template <int i> class X{};
template <class T> class Y{};

// c++98中， 如果在实例化模板的时候出现了连续两个>, 需要用空格分隔

Y<X<1> > x1;    // 编译成功
Y<X<2>> x2;     // 编译失败

// g++ -std=c++98 4-1-1.cpp