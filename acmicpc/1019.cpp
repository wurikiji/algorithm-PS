#include <cstdio>
#include <cmath>
#include <cstring>

long long dap[16][16]; 
long long getCount(char *buf, int current, int depth) {
    int len = strlen(buf);
    int cMax;
    if (len == 1) {
        cMax = buf[0] - '0';
    } else {
        cMax = buf[len - 1 - depth] - '0';
    }
    long long limit;
    long long 
    if (depth == 0) {
        dap[depth][current] = (current == 0? 0: cMax >= current? 1: 0);
    } else if (dap[depth][current] == -1){
        dap[depth][current] = getCount(buf, current, depth - 1) * (cMax + 1) + 1;
    }
    return dap[depth][current];
}
int main(void){ 
    long long n;
    char buf[16];
    scanf("%lld", &n);
    int tens = log10(n);
    memset(dap, -1, sizeof(dap));
    sprintf(buf, "%lld", n);

    for (long long i = 0;i < 10;i++) {
        printf("%lld ", getCount(buf, i, tens));
    }
    
    return 0;
}
