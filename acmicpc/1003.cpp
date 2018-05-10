#include <cstdio>
int zero, one;

int fibonacci(int n) {
    if (n==0) {
        zero++;
        return 0;
    } else if (n == 1) {
        one++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci (n-2);
    }
}

int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        zero = 0;
        one = 0;
        fibonacci(n);
        printf("%d %d\n", zero, one);
    }
    return 0;
}