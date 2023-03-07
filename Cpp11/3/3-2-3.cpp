class Info { 
public: 
    Info() { InitRest(); } 
    Info(int i) : Info() { type = i; }  //委派构造函数不能有初始化列表
    Info(char e): Info() { name = e; } 
private: 
    void InitRest() { /* 其他初始化 */ } 
    int type {1}; 
    char name {'a'}; 
    // ... 
};