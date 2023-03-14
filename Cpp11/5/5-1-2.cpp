#include <iostream>
using namespace std;

enum Type { General, Light, Medium, Heavy };
// enum Category { General, Pistol, MachineGun, Cannon };  //无法通过编译，重复定义了General
enum Category { Pistol, MachineGun, Cannon };


struct Killer {
    Killer(Type t, Category c):type(t), category(c){}
    Type type;
    Category category;
};

int main(){
    Killer cool(General, MachineGun);
    // ...
    // ... 其他很多代码 ...
    // ...
    if(cool.type >= Pistol)
        cout << "It is not a pistol" << endl;
    // ...
    cout << is_pod<Type>::value << endl;        // 1
    cout << is_pod<Category>::value << endl;    // 1

    return 0;
}