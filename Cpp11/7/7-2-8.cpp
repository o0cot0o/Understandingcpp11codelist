void Func(int i) {};
void Func(char c) = delete;     // 显示删除char版本

int main(){
    Func(3);
    Func('c');          // 本句无法通过编译
    return 1;
}