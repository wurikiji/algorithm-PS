#include <cstring>
#include <algorithm>
#include <cstdio>


using namespace std;
int n,m;
char arr[12][12];
int bx,by;
int rx,ry;
int ox,oy;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dap;

void solve(int depth) {
	int ret = 11;

	if (depth >= 10 || depth >= dap) 
		return;
	
	
	int j;
	int goal;
	int bbx = bx, bby = by;
	int rrx = rx, rry = ry;
	for (int i = 0 ;i < 4;i++) {
		goal = 0;
		bx = bbx; by = bby;
		rx = rrx; ry = rry;
		if (dx[i]) {
			if ( (dx[i] > 0 && bx > rx) ||
					(dx[i] < 0 && bx < rx)) {
				for (j = bx + dx[i]; arr[j][by] != '#'; ) {
					if (arr[j][by] == 'O')
						goal = 2;
					j+= dx[i];
				}
				bx = j - dx[i];
				for (j = rx + dx[i];arr[j][ry] != '#'; ) {
					if (arr[j][ry] == 'O') {
						goal++;
					}
					j+= dx[i];
				}
				rx = j - dx[i];
				if (ry == by && rx == bx)
					rx -= dx[i];
			} else {
				for (j = rx + dx[i];arr[j][ry] != '#'; ) {
					if (arr[j][ry] == 'O') {
						goal++;
					}
					j += dx[i];
				}
				rx = j - dx[i];
				for (j = bx + dx[i];arr[j][by] != '#'; ) {
					if (arr[j][by] == 'O')
						goal = 2;
					j += dx[i];
				}
				bx = j - dx[i];
				if (ry == by && rx == bx)
					bx -= dx[i];
			}
		} else {
			if ((dy[i] > 0 && by  > ry) ||
					(dy[i] < 0 && by < ry)) {
				for (j = by + dy[i]; arr[bx][j] != '#'; ) {
					if (arr[bx][j] == 'O')
						goal = 2;
					j += dy[i];
				}
				by = j - dy[i];
				for (j = ry + dy[i]; arr[rx][j] != '#'; ) {
					if (arr[rx][j] == 'O')
						goal++;
					j += dy[i];
				}
				ry = j - dy[i];
				if (ry == by && rx == bx)
					ry -= dy[i];
			} else {
				for (j = ry + dy[i]; arr[rx][j] != '#'; ) {
					if (arr[rx][j] == 'O')
						goal++;
					j += dy[i];
				}
				ry = j - dy[i];
				for (j = by + dy[i]; arr[bx][j] != '#'; ) {
					if (arr[bx][j] == 'O')
						goal = 2;
					j += dy[i];
				}
				by = j - dy[i];
				if (ry == by && rx == bx)
					by -= dy[i];
			}
		}
		if (goal == 1) 
		{
			dap = min(dap, depth + 1);
			return ;
		}
		else if (goal == 0) 
			solve(depth + 1);
	}
}

int main(void){ 

	scanf("%d %d", &n, &m);

	for(int i =0 ; i < n; i++) {
		scanf("%s", arr[i]);
		for(int j = 0 ; j < m; j++) {
			char c = arr[i][j];
			if (c == 'B') {
				bx = i;
				by = j;
			} else if (c  == 'R') {
				rx = i;
				ry = j;
			} else if (c == 'O') {
				ox = i;
				oy = j;
			}
		}
	}

	dap = 12;
	solve(0);

	printf("%d\n", dap > 10? -1: dap);
	return 0;
}
