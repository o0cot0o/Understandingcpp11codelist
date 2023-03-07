#include <iostream> 
using namespace std;

class DCExcept { 
public: 
    DCExcept(double d) 
        try : DCExcept(1, d) { 
            cout << "Run the body." << endl; 
            // 其他初始化
        } catch(...) { 
            cout << "caught exception." << endl; 
        } 
private: 
    DCExcept(int i, double d){ 
        cout << "going to throw!" << endl; 
        throw 0; 
    } 
    int type; 
    double data; 
}; 

int main() { 
    DCExcept a(1.2); //在目标构造函数中抛出了异常，委派构造函数的函数体部分的代码并没有被执行
    //output:
    //going to throw!
    //caught exception.
    //terminate called after throwing an instance of 'int'
    //Aborted
}