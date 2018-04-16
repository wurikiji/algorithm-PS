#include <cstdio>
#include <cstring>

void hanoi(int x, int from, int to, int other) {
    if (x == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(x-1, from, other, to);
    printf("%d %d\n", from, to);
    hanoi(x-1, other, to, from);
}
int main(void){ 
    int n;
    char buf[128];
    scanf("%d", &n);
    long double k = 1;
    for(int i = 0;i < n;i++) {
        k *= 2;
    }

    sprintf(buf, "%.0Lf", k);

    int len = strlen(buf);
    buf[len-1] = buf[len-1] - '0' - 1 + '0';
    printf("%s\n", buf);
    if (n <= 20) {
        hanoi(n, 1, 3, 2);
    }
    return 0;
}