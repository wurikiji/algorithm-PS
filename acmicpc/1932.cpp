#include <cstdio>

int max(int a, int b) {
    return a > b? a: b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[128000] = {0,};
    int dap[128000] = {0,};

    for(int i = 0;i < n * (n + 1) / 2;i++) {
        scanf("%d", arr + i);
    }

    dap[0] = arr[0];
    for(int i = 0;i < n;i++) {
        int start = i * (i + 1) / 2;
        int next = (i + 1 ) * (i + 2) /2;
        for(int j = 0 ;j < i + 1;j++) {
            dap[next + j] = max(dap[next + j]
                            ,dap[start + j] + arr[next + j]);
            dap[next + j + 1] = max(dap[next + j + 1]
                            ,dap[start + j] + arr[next + j + 1]);
        }
    }

    int start = (n - 1) * n / 2;
    for(int i = 0;i < n;i++) {
        dap[0] = max(dap[0], dap[start + i]);
    }
    printf("%d\n", dap[0]);
    return 0;
}