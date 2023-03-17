class const_val_lambda{
public:
    const_val_lambda(int v):val(v){}

public:
    void operator()()const { val = 3; }     /* 注意：常量成员函数*/

private:
    int val;
};