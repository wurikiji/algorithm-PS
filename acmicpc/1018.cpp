#include <cstdio>
#include <string>

using namespace std;

char chess[64][64];


string sample[2] = {"WBWBWBWB", "BWBWBWBW"};

int countPainting(int x, int y) {
    int count = 128;
    char buf[3] = "WB";
    for (int i = 0 ;i < 2;i++) {
        int temp = 0;
        for (int j = 0; j < 8;j++) {
            for (int k = 0 ;k < 8;k++) {
                if (chess[x+j][y+k] != sample[((j+i)%2)][k]) {
                    temp++;
                }
            }
        }
        count = min(count, temp);
    }
    return count;
}

int main(void){ 
    int m,n;
    int dap; 
    scanf("%d %d", &n, &m);

    for (int i = 0;i < n;i++) {
        scanf("%s", chess[i]);
    }
    dap = 128;
    for (int i =0 ;i + 7< n;i++) {
        for(int j = 0 ;j + 7< m;j++) {
            int temp =  countPainting(i,j);
            dap = min(dap, temp);
        }
    }
    printf("%d\n", dap);
    return 0;
}

/* 
BBBWBWBW
BBBBWBWB
BBBWBWBW
BBBBWBWB
BBBWBWBW
BBBBWBWB
BBBWBWBW
BBBBWBWB
*/