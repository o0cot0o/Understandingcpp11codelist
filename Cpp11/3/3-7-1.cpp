struct Student{
    Student(bool g, int a): gender(g), age(a) {}
    bool gender;
    int age;
};

union T {
    Student s;      //编译失败，不是一个POD类型
    int id;
    char name[10];
};

// g++ =std=c++98 3-7-1.cpp