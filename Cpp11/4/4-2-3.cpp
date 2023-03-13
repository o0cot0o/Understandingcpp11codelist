#include <string>
#include <vector>

void loopover(std::vector<std::string> &vs){
    // std::vector<std::string>::iterator i = vs.begin(); // 想要使用iterator,往往需要写大量代码

    // for(; i < vs.end(); i++){
    //     // 一些代码
    // }

    // 使用auto 4-2-4.cpp
    for(auto i = vs.begin(); i < vs.end(); i++){
        // 一些代码
    }
}