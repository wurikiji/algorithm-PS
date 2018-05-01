#include <cstring>
#include <cstdio>

int main(void){ 
    char a[64];
    char b[64];
    scanf("%s %s", a, b);
    int alen = strlen(a);
    int blen = strlen(b);

    int minmin = 128;
    for(int i = 0 ;i <= blen-alen;i++) {
        int cnt = 0;
        for(int j = 0 ;j < alen;j++) {
            if (a[j] != b[j + i]) cnt++;
        }
        if (cnt < minmin) minmin = cnt;
    }
    printf("%d\n", minmin);
    return 0;
}