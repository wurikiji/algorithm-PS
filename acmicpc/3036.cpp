#include <cstdio>


int gcd[1024] = {0,};
int _gcd( int a, int b) {
    int __gcd;
    if (gcd[b] != 0){
        return gcd[b];
    }
    while(b != 0) {
        __gcd = a;
        a = b;
        b = __gcd % a;
    }
    return a;
}
int main(void){ 
    int n;
    int arr[128];
    scanf("%d", &n);
    for(int i = 0 ;i < n;i++) {
        scanf("%d", arr + i);
        if (i) {
            gcd[arr[i]] = _gcd(arr[0], arr[i]);
            printf("%d/%d\n", arr[0] / gcd[arr[i]], arr[i] / gcd[arr[i]]);
        }
    }

    return 0; 
}