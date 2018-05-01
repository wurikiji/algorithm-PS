#include <cstdio>

long long gcd ( long long a, long long b) {
    long long gcd;
    while(b != 0) {
        gcd = a;
        a = b;
        b = gcd % a;
    }
    return a;
}
int main(void){ 
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long _gcd = gcd(a, b);
    long long lcm = a * b / _gcd;
    printf("%lld\n", lcm);
    return 0;
}