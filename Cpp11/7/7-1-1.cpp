#include <stdio.h>

void f(char* c){
    printf("invoke f(char*)\n");
}

void f(int i){
    printf("invoke f(int)\n");
}

int main() {
    f(0);
    f(NULL);        // 注意：如果gcc编译，NULL转化为内部标识__null，该语句会编译失败
    f((char*)0);
}

// xlC -+ 7-1-1.cpp 

// 结果：
// invoke f(int)
// invoke f(int)
// invoke f(char*)