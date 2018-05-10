#include <cstdio>
int main(void){ 
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0 ;i < 5;i++) {
        int t;
        scanf("%d", &t);
        if (t == n) cnt ++;
    }
    printf("%d\n", cnt);
    return 0;
}