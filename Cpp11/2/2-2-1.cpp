#if __cplusplus < 201103L
    #error "should use C++11 implementation" 
#endif

#include <climits>
#include <cstdio>
using namespace std; 

int main() { 
    long long ll_min = LLONG_MIN; 
    long long ll_max = LLONG_MAX; 
    unsigned long long ull_max = ULLONG_MAX; 
    printf("min of long long: %lld\n", ll_min); // min of long long: -9223372036854775808 
    printf("max of long long: %lld\n", ll_max); // max of long long: 9223372036854775807 
    //printf 有符号long long %lld
    printf("max of unsigned long long: %llu\n", ull_max); // max of unsigned long long: 18446744073709551615 
    //printf 无符号符号long long %llu
}