#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
    int n;
    scanf("%d", &n);
    int arr[1010101];
    for(int i = 0 ;i < n;i++) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);

    for(int i = 0 ;i < n;i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}