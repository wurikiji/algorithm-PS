#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n, m, x, y, c;
int arr[32][32];

int we = 0;
int areh = 0; 
int ap = 0; 
int dui = 0; 
int lll = 0; 
int rrr = 0;


int bound(int xx, int yy) {
	return xx >= 0 && yy >= 0 && xx < n && yy < m;
}

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void lr_move(int d) {
	int tmp = we;
	if (d < 0) {
		we = rrr;
		rrr = areh;
		areh = lll;
		lll = tmp;
	} else {
		we = lll;
		lll = areh;
		areh = rrr;
		rrr = tmp;
	}
}

void bf_move(int d) {
	int tmp = we;
	if (d < 0) {
		we = ap;
		ap = areh;
		areh = dui;
		dui = tmp;
	} else {
		we = dui;
		dui = areh;
		areh = ap;
		ap = tmp;
	}
}

void solve(int d) {
	int nx, ny;
	nx = x + dx[d];
	ny = y + dy[d];
	if (bound(nx, ny)) {
		x = nx; y = ny;

		(dy[d]? lr_move(dy[d]): bf_move(dx[d]));

		printf("%d\n", we);

		if (arr[x][y] == 0)
			arr[x][y] = areh;
		else {
			areh = arr[x][y];
			arr[x][y] = 0;
		}
	}
}

int main(void){ 
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &c);

	for (int i = 0 ;i < n; i++) {
		for (int j = 0 ;j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int i = 0 ;i < c;i++) {
		int d;
		scanf("%d", &d);
		solve(d);
	}
	return 0;
}
