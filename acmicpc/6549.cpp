#include <cstdio>

int arr[101010];
int main(void){ 
    while(1) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        for(int i = 0 ;i < n;i++) {
            scanf("%d", arr + i);
        }
    }
    return 0;
}