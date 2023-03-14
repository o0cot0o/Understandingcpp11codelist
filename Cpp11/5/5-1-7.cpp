// 匿名的enum class什么都做不了
enum class { General, Light, Medium, Heavy }weapon;

int main() {
    weapon = General;       // 无法通过编译
    bool b = (weapon == weapon::General);   // 无法通过编译
    return 0;
}