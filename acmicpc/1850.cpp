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
    long long alen, blen;
    scanf("%lld %lld", &alen, &blen);
    long long gcdLen = gcd(alen, blen);
    for(int i = 0 ;i < gcdLen;i++) 
        printf("1");
    printf("\n");
    return 0;
}