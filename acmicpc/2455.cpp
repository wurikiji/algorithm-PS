#include <cstdio>


int max(int a, int b){
    return a > b ? a : b;
}
int main(void){ 
    int out, in;
    int cur = 0;
    int max = 0;
    for(int i = 0 ;i < 4;i++) {
        scanf("%d %d", &out, &in);
        cur -= out;
        cur += in;
        if (max < cur) 
            max = cur;
    }
    printf("%d\n", max);
    return 0;
}