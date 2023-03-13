#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    typedef decltype(vec.begin()) vectype;

    for(vectype i = vec.begin(); i < vec.end(); i++){
        // 做一些事情
    }

    for(decltype(vec)::iterator i = vec.begin(); i < vec.end(); i++){
        // 做一些事情
    }
}