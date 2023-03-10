#include <stdio.h>

#define LOG(...) {\
    fprintf(stderr,"%s: Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\ 
    fprintf(stderr,"\n");\ 
}

int main() { 
    int x = 3; 
    // 一些代码 ... 
    LOG("x = %d", x); // 2-1-5.cpp: Line 12: x = 3 
    // __VA_ARGS__被替换为了下面的"x = %d", x
}