#include <cstdio>

int main(void){ 
    int n,m,k;
    int a[128][128];
    int b[128][128];
    int mult[128][128];
    scanf("%d %d", &n, &m);
    for(int i = 0 ;i < n;i++) {
        for(int j =0 ;j < m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &m, &k);
    for(int i = 0 ;i < m;i++) {
        for(int j = 0 ;j < k;j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 0 ;i < n;i++) {
        for(int j = 0 ;j < k;j++) {
            for(int q = 0 ; q < m; q++) {
                mult[i][j] += (a[i][q] * b[q][j]);
            }
            if (j) printf(" ");
            printf("%d", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}