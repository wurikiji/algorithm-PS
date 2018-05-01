#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
    int n;
    scanf("%d", &n);
    int a[64];
    int b[64];
    for(int i = 0 ;i < n;i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for(int i = 0 ;i < n;i++) {
        scanf("%d", b + i);
    }
    sort(b, b + n);
    reverse(b, b+ n);
    int dap = 0;
    for(int i = 0 ;i < n;i++) {
        dap += a[i] * b[i];
    }
    printf("%d\n", dap);
    return 0;
}