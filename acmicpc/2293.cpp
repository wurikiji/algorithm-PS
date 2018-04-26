#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
    int n, k;
    int arr[128];
    int arr[10010];
    scanf("%d %d", &n, &k);
    for(int i = 0 ;i < n;i++) {
        scanf("%d", arr + i);
    }

    sort(arr, arr + n);

    for(int i = 1 ;i <= k;i++) {
    }
    return 0;
}