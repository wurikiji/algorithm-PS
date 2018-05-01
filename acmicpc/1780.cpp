#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<int> > v;

int arr[8];
void divide(int x, int y, int len) {
    bool clean = true;
    for(int i = 0;i < len ;i++) {
        for(int j = 0;j < len;j++) {
            if (v[x + i][y + j] != v[x][y]) {
                clean = false;
                break;
            }
        }
    }
    if (clean) {
        arr[v[x][y] + 1]++;
    } else {
        for(int i = 0 ;i < 3;i++) {
            for(int j =0 ;j < 3;j++) {
                divide(x + len/3 * i, y + len/3 * j, len/3);
            }
        }
    }
}

int main(void){ 
    int n;
    scanf("%d", &n);
    for(int i = 0 ;i < n;i++) {
        vector<int> temp;
        for(int j = 0 ;j < n;j++) {
            int a;
            scanf("%d", &a);
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    
    memset(arr, 0, sizeof(arr));
    divide(0,0, n);
    for(int i = 0 ;i < 3;i++)
        printf("%d\n", arr[i]);

    return 0;
}