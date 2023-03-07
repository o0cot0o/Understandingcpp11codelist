#include <initializer_list> // 自定义类使用初始化列表需要 包含头文件
#include <vector>
#include <map>
#include <string>
using namespace std;

enum Gender {boy, girl};
class People {
public:
    People(initializer_list<pair<string, Gender>> l){ // 自定义类使用初始化列表需要 包含声明模板类作为参数的构造函数
        auto i = l.begin();
        for(; i != l.end(); ++i)
            data.push_back(*i);

    }
private:
    vector<pair<string, Gender>> data;
};

People ship2012 = {{"Garfield", boy}, {"HelloKitty", girl}};