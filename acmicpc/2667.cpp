#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct point {
    int x;
    int y;
    point(int a, int b) : x(a), y(b) {}
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool inBound(int x, int y, int mx, int my) {
    return x >= 0 && y >= 0 && x < mx && y < my;
}
bool chk[32][32] = {false,};
int bfs(char arr[32][32], int x, int y, int n, int m) {
    queue<point> q;
    q.emplace(x,y);
    chk[x][y] = true;
    int cnt = 1;
    while(!q.empty()) {
        point nxt = q.front();
        q.pop();
        for(int i = 0 ;i < 4;i++) {
            int nx = nxt.x + dx[i];
            int ny = nxt.y + dy[i];
            if (inBound(nx,ny,n,m) && arr[nx][ny] == '1' && chk[nx][ny] == false) {
                chk[nx][ny] = true;
                q.emplace(nx,ny);
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void){ 
    int n;
    char arr[32][32];
    scanf("%d", &n);
    for(int i = 0 ;i < n;i++) {
        scanf("%s", arr[i]);
    }

    vector<int> house;
    for(int i = 0 ;i < n;i++) {
        for(int j = 0 ;j < n;j++) {
            if (arr[i][j] == '1' && chk[i][j] == false) {
                int cnt = bfs(arr, i, j, n, n);
                house.push_back(cnt);
            }
        }
    }
    sort(house.begin(), house.end());
    printf("%d\n", house.size());
    for(int i = 0 ;i < house.size();i++) {
        printf("%d\n", house[i]);
    }
    return 0;
}