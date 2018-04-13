#include <cstdio>
#include <cstring>

int _max;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[512][512];
long long dap[512][512];

int n, m;

int max(int x, int y) {
	return x > y ? x : y;
}
long long solve(int x, int y) {
	if (x == n-1 && y == m-1){
		return 1;
	}
    if (dap[x][y] != -1)
        return dap[x][y];
    dap[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m 
            && arr[nx][ny] < arr[x][y] ) {
			dap[x][y] += solve(nx, ny);
		}
	}
    return dap[x][y];
}
int main(void) {
	scanf("%d %d", &n, &m);
    memset(dap, 0xff, sizeof(dap));
	for(int i = 0;i < n ;i ++) {
		for(int j = 0 ;j < m;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
    
	printf("%lld\n", solve(0,0));
	return 0;
}

