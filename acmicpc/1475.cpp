#include <cstdio>
#include <cstring>

int main(void) {
    char buf[16];
    scanf("%s", buf);
    int len = strlen(buf);
    int cnt = 0;
    int arr[10] = {0};
    for(int i = 0 ;i < len;i++) {
        if (buf[i] == '9') {
            arr[6]++;
        } else {
            arr[buf[i] - '0']++;
        }
    }
    int mmax = 0;
    arr[6] = (arr[6] + 1) /2;
    for(int i = 0 ;i < 10;i++) {
        if (mmax < arr[i]) {
            mmax = arr[i];
        }
    }
    printf("%d\n", mmax);
    return 0;
}