#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int getGap(int col) {
    int gap = 8 * abs(col - 1);
    return col < 0? -gap : gap;
}

int main(void){ 
    int r1, c1, r2, c2;
    int arr[64][8]; 
    int maxLen = 0;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for(int i = 0; i <= r2 - r1;i++) {
        int gap = getGap(r1 + i);
        int start = 1 + ;
        for(int j = 0; j <= c2 - c1;j++) {
            if (abs(c1 + j) <= abs(r1 +i)) { 
                if (r1 + i < 0) {
                    arr[i][j] = start - i;
                } else if (r1 + i > 0) {
                    arr[i][j] = start + i;
                } else {
                    arr[i][j] = start + getGap(c1 + i);
                }
            } else {
                if (r1 + i < 0) {
                    arr[i][j] = start - i;
                } else if (r1 + i > 0) {
                    arr[i][j] = start + i;
                } else {
                    arr[i][j] = start + getGap(c1 + i);
                }
            }
            if (log10(arr[i][j]) > maxLen) {
                maxLen = log10(arr[i][j]);
            }
        }
    }
    for(int i = 0 ;i <= r2 - r1;i++) {
        for(int j = 0 ;j <= c2 - c1;j++) {
            int len = log10(arr[i][j]);
            if(j) printf(" ");
            for(int k = 0 ; k < maxLen - len;k++) {
                printf(" ");
            }
            printf("%d", arr[i][j] < 0 ? -arr[i][j]: arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}