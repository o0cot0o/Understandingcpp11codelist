#include <iostream>
#include <type_traits>
using namespace std;

struct SLayout1 {};
struct SLayout2 {};

struct SLayout3 : SLayout1 {
    int x;
    int y;
    void f();
};
struct SLayout4 : SLayout1, SLayout3 {};
struct SLayout5 : SLayout2, SLayout3 {};

int main(){
    SLayout4 sl4;
    SLayout5 sl5;
    cout << sizeof(sl4) << endl;        // 12
    cout << sizeof(sl5) << endl;        // 8
    
    cout << hex;
    cout << reinterpret_cast<long long> (&sl4) << endl;         // 7ffe06afca20
    cout << reinterpret_cast<long long> (&sl4.x) << endl;       // 7ffe06afca24
    cout << reinterpret_cast<long long> (&sl4.y) << endl;       // 7ffe06afca28

    cout << reinterpret_cast<long long> (&sl5) << endl;         // 7ffe06afca18
    cout << reinterpret_cast<long long> (&sl5.x) << endl;       // 7ffe06afca18
    cout << reinterpret_cast<long long> (&sl5.y) << endl;       // 7ffe06afca1c


    cout << is_standard_layout<SLayout4>::value << endl;        // 0
    cout << is_standard_layout<SLayout5>::value << endl;        // 1
    return 0;
}