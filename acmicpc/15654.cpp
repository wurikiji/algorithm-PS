#include <cstdio>
#include <algorithm>

using namespace std;

void printer(int *init, int *arr, int n, int m, int depth) {
    if (m == depth) {
        for(int i = 0 ;i < m;i++) {
            if (i) printf(" ");
            printf("%d", init[arr[i]]);
        }
        printf("\n");
        return ;
    }
    bool idx[16] = {1,1,1,1,1,1,1,1,1,1,1};
    for(int i = 0;i < depth;i++) {
        idx[arr[i]] = false;
    }
    for(int i = 0;i < n;i++) {
        if (idx[i]) {
            arr[depth] = i;
            printer(init, arr, n, m, depth + 1);
        }
    }
}
int main(void){ 
    int n, m;
    scanf("%d %d", &n, &m);
    int init[16];
    int arr[16];
    for(int i = 0 ;i < n;i++) {
        scanf("%d", init + i);
    }
    sort(init, init + n);
    printer(init, arr, n, m, 0);
    return 0;
}