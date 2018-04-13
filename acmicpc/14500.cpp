#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>


int x[5][4][4] ={
	{ 
		{0,0,0,0}, {0,0,0,0},
		{0,1,2,3}, {0,-1,-2,-3}
	},

	{ 
		{0,0,1,1}, {0,0,1,1},
		{0,0,-1,-1}, {0,0,-1,-1}
	},

	{ 
		{0,0,-1,-2}, {0,0,0,1},
		{0,0,1,2}, {0,0,0,-1}
	},

	{ 
		{0,-1,-1,-2}, {0,0,-1,-1},
		{0,1,1,2}, {0,0,1,1,}
	},

	{ 
		{0,0,0,1}, {0,0,0,-1},
		{0,1,1,2}, {0,-1,-1,-2}
	}
};

int y[5][4][4] = {
	{ 
		{0,1,2,3}, {0,-1,-2,-3},
		{0,0,0,0}, {0,0,0,0}
	},

	{
		{0,1,0,1}, {-1,0,-1,0},
		{0,1,0,1}, {-1,0,-1,0}
	},

	{
		{0,1,0,0}, {0,1,2,0},
		{0,-1,0,0}, {0,-1,-2,0}
	},

	{
		{0,0,-1,-1}, {0,1,1,2},
		{0,0,1,1}, {0,-1,-1,-2}
	},

	{
		{0,1,2,1}, {0,-1,-2,-1},
		{0,0,-1,0}, {0,0,1,0}
	},
};
int bound(int x,int y, int mx, int my) 
{
	return x >= 0 && y >= 0 && x < mx && y < my;
}
int main(void){ 
	int n, m;
	int arr[512][512];
	long long max_ = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n ;i++) {
		for(int j = 0 ;j < m ;j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
	for (int j = 0;j < m;j++) {
		for (int q = 0 ;q < 5; q++) {
			for (int w = 0 ;w < 4; w++) {
				long long sum = 0;
				int e;
				for (e = 0 ;e < 4; e++) {
					int nx = i + x[q][w][e];
					int ny = j + y[q][w][e];
					if (bound(nx,ny, n, m)) {
						sum += arr[ i + x[q][w][e] ] [ j + y[q][w][e] ];
					}else
						break;
				}
				if (e == 4 && max_ < sum)
					max_  = sum;
				sum = 0;
				for (e = 0 ;e < 4; e++) {
					int nx = i + x[q][w][e];
					int ny = j - y[q][w][e];
					if (bound(nx,ny, n, m)) {
						sum += arr[ i + x[q][w][e] ] [ j + y[q][w][e] ];
					}else
						break;
				}
				if (e == 4 && max_ < sum)
					max_  = sum;
				sum = 0;
				for (e = 0 ;e < 4; e++) {
					int nx = i - x[q][w][e];
					int ny = j + y[q][w][e];
					if (bound(nx,ny, n, m)) {
						sum += arr[ i + x[q][w][e] ] [ j + y[q][w][e] ];
					}else
						break;
				}
				if (e == 4 && max_ < sum)
					max_  = sum;
			}
		}
	}
	}
	printf("%lld\n", max_);
	return 0;
}

