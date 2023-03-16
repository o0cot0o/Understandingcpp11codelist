#include <iostream>
using namespace std;

void f(char* c){
    printf("invoke f(char*)\n");
}

void f(int i){
    printf("invoke f(int)\n");
}

int main() {
    f(nullptr);     // 调用f(char*) 版本
    f(0);           // 调用f(int) 版本
    return 0;
}