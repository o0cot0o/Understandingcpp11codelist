class ConvertTo{};
class Convertable{
public:
    // 显示转换为ConvertTo类型
    // eplicit 作用于类型转换操作符上，只有在直接构造目标类型或显示类型转换时才可以使用该类型
    explicit operator ConvertTo() const { return ConvertTo(); }
};

void Func(ConvertTo ct) {}
void test() {
    Convertable c;          
    ConvertTo ct(c);        //直接初始化，通过
    ConvertTo ct2 = c;      //拷贝构造初始化，编译失败
    ConvertTo ct3 = static_cast<ConvertTo>(c);  // 强制转换，通过
    Func(c);                //拷贝构造初始化，编译失败
}