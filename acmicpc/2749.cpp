#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
typedef vector< vector<long long> > matrix;
#define MOD (1000000)

matrix operator*(const matrix &a, const matrix &b) {
	int sz = a.size();
	matrix ret(sz, vector<long long>(sz));

	for(int i = 0 ;i < sz;i++) {
		for(int j = 0 ;j < sz;j++) {
			ret[i][j] = 0;
			for(int k = 0 ;k < sz;k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}

	return ret;
}


int main(void){ 
	long long n;
	scanf("%lld", &n);
	matrix dap = {{1, 0}, {0, 1}};
	matrix mult = {{1, 1}, {1, 0}};

	while(n) {
		if (n%2 == 1) {
			dap = dap * mult;
		}
		mult = mult * mult;	
		n /= 2;
	}
	printf("%lld\n", dap[0][1]);
	return 0;
}
