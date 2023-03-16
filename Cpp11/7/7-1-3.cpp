#include <cstddef>
#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    // nullptr 可以隐式转换为 char*
    char* cp = nullptr;

    // 不可转换为整型，而任何类型也不能转换为nullptr_t.
    // 以下代码不可通过编译
    // int n1 = nullptr;
    // int n2 = reinterpret_cast<int>(nullptr);

    // nullptr与nullptr_t 类型变量可以作比较，
    // 当使用==、 <=、 >=符合比较时返回true
    nullptr_t nptr;
    if(nptr == nullptr)
        cout << "nullptr_t nptr == nullptr" << endl;
    else
        cout << "nullptr_t nptr != nullptr" << endl;
    
    if(nptr < nullptr)          // c++17 error: invalid operands to binary expression ('std::nullptr_t' and 'std::nullptr_t')
        cout << "nullptr_t nptr < nullptr" << endl;
    else
        cout << "nullptr_t nptr !< nullptr" << endl;

    // 不能转换为整型或bool类型，以下代码不能通过编译
    // if(0 == nullptr);   // 编译器过老，只有警告
    // if(nullptr);

    // 不可以进行算术运算，以下代码不能通过编译
    // nullptr += 1;
    // nullptr * 5;

    // 以下操作均可以正常运行
    sizeof(nullptr);
    typeid(nullptr);
    throw(nullptr);

    return 0;
}