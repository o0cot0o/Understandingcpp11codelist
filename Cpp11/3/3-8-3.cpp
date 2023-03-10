struct Watt{ unsigned int v; };
                                            // 后缀建议以下划线开始
Watt operator "" _w(unsigned long long v){  // operator"" 和用户自定义后缀之间必须有空格
    return { (unsigned int)v };
}

int main() {

    Watt capacity = 1024_w;
}

/*
c++11 字面量规则
字面量      字面量操作符                         注意
整型        unsigned long long 、 const char*   当unsigned long long无法容纳时，自动转为\0结束的字符串，并调用const char*参数版本的
浮点型      long double、 const char*           过长则使用const char*版本
字符串      const char*、 size_t
字符        char
*/