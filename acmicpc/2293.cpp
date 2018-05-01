#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
    int n, k;
    int arr[128];
    int dap[10010] = {0,};
    scanf("%d %d", &n, &k);
    for(int i = 0 ;i < n;i++) {
        scanf("%d", arr + i);
        if (arr[i] <= 10000) {
            dap[arr[i]]++;
            for(int j = arr[i]; j <= k;j++) {
                dap[j] += dap[j - arr[i]];
            }
        }
    }
    printf("%d\n", dap[k]);
    return 0;
}