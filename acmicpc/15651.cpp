#include <cstdio>
#include <vector>


void printer(int *arr, int n, int m, int depth){
    if (m == depth) {
        for(int i = 0 ;i < m;i++) {
            if (i) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 1;i <= n;i++) {
        arr[depth] = i;
        printer(arr, n, m, depth + 1);
    }
}

int main(void){
    int n,m;
    int arr[16];
    scanf("%d %d", &n, &m);

    printer(arr, n, m, 0);
    return 0;
}