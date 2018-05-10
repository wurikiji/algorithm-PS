#include <cstdio>

int main(void) { 
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[16][16] = {0, };

    for(int i = 0 ;i <n ;i++) {
        for(int j = 0 ;j < m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}
