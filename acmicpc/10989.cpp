#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
    int n;
    scanf("%d", &n);
    int arr[10010] = {0};
    for(int i = 0 ;i < n;i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp]++;
    }

    for(int i = 0 ;i < 10001;) {
        if (arr[i]) {
            printf("%d\n", i);
            arr[i]--;
        } else {
            i++;
        }
    }
    return 0;
}