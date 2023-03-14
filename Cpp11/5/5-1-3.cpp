#include <iostream>
using namespace std;

class Type {
public:
    enum type { general, light, medium, heavy };
    type val;
public:
    Type(type t): val(t){}
    bool operator >= (const Type & t){ return val >= t.val; }
    static const Type General, Light, Medium, Heavy;
};

const Type Type::General(Type::general);
const Type Type::Light(Type::light);
const Type Type::Medium(Type::medium);
const Type Type::Heavy(Type::heavy);

class Category{ 
public:
public:
    enum category { pistol, machineGun, cannon};
    category val;
public:
    Category(category t): val(t){}
    bool operator >= (const Category & t){ return val >= t.val; }
    static const Category Pistol, MachineGun, Cannon;
};

const Category Category::Pistol(Category::pistol);
const Category Category::MachineGun(Category::machineGun);
const Category Category::Cannon(Category::cannon);

struct Killer {
    Killer(Type t, Category c):type(t), category(c){}
    Type type;
    Category category;
};

int main(){
    // 使用类型包装后的enum
    Killer notCool(Type::General, Category::MachineGun);
    // ...
    // ... 其他很多代码 ...
    // ...
    if(notCool.type >= Type::General)           // 可以通过编译
        cout << "It is not a general" << endl;
    // if(notCool.type >= Category::Pistol)           // 该句无法通过编译
    //     cout << "It is not a pistol" << endl;
    // ...
    cout << is_pod<Type>::value << endl;        // 0
    cout << is_pod<Category>::value << endl;    // 0

    return 0;
}