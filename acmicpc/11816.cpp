#include <cstdio>
#include <cstring>
#include <cmath>

void print8(char *buf, int len) {
    int dap = 0;
    for(int i = 0 ;i < len;i++) {
        dap += (buf[len-1-i] - '0') * pow(8,i);
    }
    printf("%d\n", dap);
}

void print16(char *buf, int len) {
    int arr[128];
    for(int i = 0 ;i < 10;i++) {
        arr['0' + i] = i;
    }
    for(int i = 0 ;i < 26;i++) {
        arr['a' + i] = 10 + i;
    }
    int dap = 0;
    for(int i = 0 ;i < len;i++) {
        dap += (arr[buf[len-1-i]]) * pow(16,i);
    }
    printf("%d\n", dap);
}

int main(void) {
    char buf[128];
    scanf("%s", buf);
    int len = strlen(buf);
    if (len > 1) {
        if (buf[0] == '0'
         && buf[1] == 'x') {
             // goto 16
             print16(buf + 2, len - 2);
        } else {
            if (buf[0] == '0') {
                // go to 8 
                print8(buf + 1, len - 1);
            } else {
                printf("%s\n", buf);
            }
        }
    } else {
        printf("%s\n",buf);
    }
}