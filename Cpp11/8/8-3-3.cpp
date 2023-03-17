#include <bits/types/mbstate_t.h>
#include <iostream>
#include <cuchar>
#include <uchar.h>
using namespace std;

int main() {
    char16_t utf16[] = u"\u4F60\u597D\u554A";
    char mbr[sizeof(utf16)*2] = {0};        // 这里我们假设buffer这么大就够了
    mbstate_t s;

    c16rtomb(mbr, utf16, &s);
    cout << mbr << endl;
}