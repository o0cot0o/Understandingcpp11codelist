#include <map>
using namespace std;

namespace test {    // 加入namespace避免与std::hash冲突
    int hash(char*);

    map<char*, decltype(hash)> dict_key;        // 无法通过编译
    map<char*, decltype(hash(nullptr))> dict_key1;  // decltype 只能接受表达式做参数
}
