#include <cstdio>

int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int k, n;
        scanf("%d", &k);
        scanf("%d", &n);
        long long arr[15] = {1};

        for(int i = 1; i <= n;i++) {
            arr[0] = i;
            for(int j = 1 ;j <= k;j++) {
                arr[j] += arr[j-1];
            }
        }
        printf("%lld\n", arr[k]);
    }
    return 0;
}
