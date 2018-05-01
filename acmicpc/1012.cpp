#include <cstdio>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
    point(int _x, int _y):x(_x), y(_y)
    {}
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inbound(int x, int y, int mx, int my) {
    return x >=0 && y >= 0 && x < mx && y < my;
}
int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int m, n, k;
        int arr[64][64] = {0,};
        bool chk[64][64] = {false,};
        scanf("%d %d %d", &m, &n, &k);
        for(int i = 0 ;i < k;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }
        int dap = 0;
        for(int i = 0 ;i < n;i++) {
            for(int j = 0 ;j < m;j++) {
                if (arr[i][j] == 1 && chk[i][j] == false) {
                    queue<point> q;
                    q.emplace(i,j);
                    chk[i][j] = true;
                    dap++;
                    while(!q.empty()) {
                        point nxt = q.front();
                        q.pop();
                        for(int k = 0 ;k < 4;k++) {
                            int nx = nxt.x + dx[k];
                            int ny = nxt.y + dy[k];
                            if (inbound(nx,ny,n,m) && arr[nx][ny] && !chk[nx][ny]){
                                chk[nx][ny] = true;
                                q.emplace(nx,ny);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", dap);
    }
    return 0;
}