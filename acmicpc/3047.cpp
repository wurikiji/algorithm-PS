#include <cstdio>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int main(void){ 
    int arr[3];
    for(int i = 0 ;i < 3;i++) {
        scanf("%d", arr+i);
        for(int j = 0;j < i;j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    char buf[8];
    scanf("%s", buf);
    for(int i= 0 ;i < 3;i++) {
        if (i) printf(" ");
        printf("%d", arr[buf[i]-'A']);
    }
    printf("\n");
    return 0;
}