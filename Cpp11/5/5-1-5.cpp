/*
强类型枚举

声明：在enum后加上关键字class

优势：
    强作用域，强类型枚举成员的名称不会被输出到其父作用域空间
    转换限制，强类型枚举成员的值不可以与整型隐式相互转换
    可以指定底层类型。默认底层类型：int
        显示指定： enum class Type:char{ General, Light};
        type可以是除了wchar_t以外的任何整型
*/

#include <iostream>
using namespace std;

enum class Type { General, Light, Medium, Heavy };
enum class Category {  General = 1, Pistol, MachineGun, Cannon};

int main(){
    Type t = Type::Light;
    t = General;                                // 编译失败，必须使用强类型名称
    if(t == Category::General)                  // 编译失败，必须使用Type中的General
        cout << "General Weapon" << endl;
    if(t > Type::General)                       // 通过编译
        cout << "Not General Weapon" << endl;
    if(t > 0)                                   // 编译失败，无法转换为int类型
        cout << "Not General Weapon" << endl;
    if((int)t > 0)                              // 通过编译
        cout << "Not General Weapon" << endl;
    cout << is_pod<Type>::value << endl;        // 1
    cout << is_pod<Category>::value << endl;    // 1
    return 0;
}