#include <cstdio>
#include <cmath>

int main(void) {
	int m, n;
	bool chk[1010101] = {0,};
	scanf("%d %d", &m, &n);
	chk[1] = true;
	for(int i = 2;i < sqrt(n) + 1;i++) {
		if (chk[i] == false) {
			for(int j = 2;j * i <= n;j++) {
				chk[j*i] = true;
			}
		}
	}
	for(int i = m; i <= n;i++) {
		if (chk[i] == false) {
			printf("%d\n", i);
		}
	}
	return 0;
}
