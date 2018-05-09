#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool inbound(int x,int y, int mx, int my) {
	return x >= 0 && y >= 0 && x < mx && y < my;
}
int main(void){ 
	int m,n;
	int arr[1024][1024];
	scanf("%d %d", &m, &n);
	queue<pair<int,int>> q;
	int fruit = n * m;
	for(int i = 0 ;i < n;i++) {
		for(int j = 0 ;j < m;j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.emplace(i,j);
			} else if (arr[i][j] == -1) {
				fruit--;
			}
		}
	}

	int count = 0;
	while(!q.empty() ){
		pair<int,int> p = q.front();
		q.pop();
		count = arr[p.first][p.second];
		fruit--;
		for(int i = 0 ;i < 4;i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (inbound(nx,ny,n,m) && arr[nx][ny] == 0) {
				arr[nx][ny] = arr[p.first][p.second] + 1;
				q.emplace(nx, ny);
			}
		}
	}
	if (count == 0 || fruit != 0) {
		printf("-1\n");
	} else {
		printf("%d\n", count - 1);
	}
	return 0;
}
