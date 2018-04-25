#include <cstdio>

int min(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[1024][8];
    int dap[1024][8];
    for(int i = 0 ;i < n;i++) {
        for(int j = 0 ;j < 3;j++) {
            scanf("%d", &arr[i][j]);
            dap[i][j] = 1024 * 1024;
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0 ;j < 3;j++) {
            if (i == 0)
                dap[i][j] = arr[i][j];
            for(int k = 0 ;k < 3;k++) {
                if (j != k) {
                    dap[i+1][k] = min(dap[i+1][k], dap[i][j] + arr[i+1][k]);
                }
            }
        }
    }
    printf("%d\n", min(dap[n-1][0], min(dap[n-1][1], dap[n-1][2])));
    return 0;
}