#include <cstdio>

int main(void){
    int n;
    scanf("%d", &n);
    int arr[1024];
    int lis[1024] = {0,};
    int mx = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d", arr + i);
        lis[i] = 1;
        for(int j = 0;j < i;j++) {
            if (arr[j] < arr[i] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
        if (lis[i] > mx) mx = lis[i];
    }
    printf("%d\n", mx);
    return 0;
}