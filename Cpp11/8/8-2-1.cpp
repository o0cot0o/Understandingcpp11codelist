extern int area(int n) __attribute__((const));  // 本函数返回值只依赖于输入。

int main(){
    int i;
    int areas = 0;
    for(i = 0; i < 10; i++){
        areas += area(3) * i;
    }
}

// 8-2-2 C++11之前__declspec(align(x))控制变量对齐方式
// __declspec(align(32)) struct Struct32 {
//     int i;
//     double d;
// };