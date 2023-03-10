#include <iostream>
using namespace std;
// 这是Jim编写的库，用Jim这个命名空间
namespace Jim {
    namespace Basic {
        struct Knife{ Knife() { cout << "Knife in Basic." << endl; } };
        class CorkScrew{};
    }
    namespace Toolkit {
        template<typename T> class SwissArmyKnife{};
    }
    // ...
    namespace Other {
        Knife b;            // 无法通过编译
        struct Knife{ Knife() { cout << "Knife in Other." << endl; } };
        Knife c;            // Knife in Other
        Basic::Knife k;     // Knife in Basic
    }
}

using namespace Jim;
int main(){
    Toolkit::SwissArmyKnife<Basic::Knife> sknife;
}