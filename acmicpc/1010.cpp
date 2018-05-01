#include <cstdio>


long long solve(int arr[32][32], int n, int m){ 
    if (n == m) return 1;
    if (n == 0) return 1;
    
    if (arr[n][m] != 0)
        return arr[n][m];
    
    for(int i = 1 ;m - i >= n - 1;i++) {
        arr[n][m] += solve(arr, n-1, m-i);
    }
    return arr[n][m];
}

int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        int arr[32][32] = {0, };
        scanf("%d %d", &n, &m);
        printf("%lld\n", solve(arr, n, m));
    }
    return 0;
}