// 不能形成委托环（delegation cycle）

class Info { 
public: 
    Info() : Info(1) { } // 委派构造函数 Info() 委托 Info(int) 进行构 造
    Info(int i) : Info(i, 'a') { } // 既是目标构造函数，也是委派构造函数 Info(int) 又委托 Info(int, char) 进行构造
    Info(char e): Info(1, e) { } 
    
private: 
    Info(int i, char e): type(i), name(e) { /* 其他初始化 */ } // 目标构造函数
    int type; 
    char name; 
    // ... 
};