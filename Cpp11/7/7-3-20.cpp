int d = 0;

class healthyFunctor{
public:
    healthyFunctor(int d):data(d){}

    void operator() () const {}

private:
    int data;
};

int TryCapture() {
    healthyFunctor hf(d);           // 仿函数可以在不同的作用域范围内取得初始值
}