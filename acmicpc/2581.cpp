#include <cstdio>
#include <cmath>

int main(void) {
	int m, n;
	bool chk[10101] = {0,};
	scanf("%d %d", &m, &n);
	chk[1] = true;
	for(int i = 2;i < sqrt(n) + 1;i++) {
		if (chk[i] == false) {
			for(int j = 2;j * i <= n;j++) {
				chk[j*i] = true;
			}
		}
	}
	int min = -1;
	int sum = 0;
	for(int i = m; i <= n;i++) {
		if (chk[i] == false) {
			if (min == -1) min = i;
			sum += i;
		}
	}
	if (min == -1) {
		printf("-1\n");
	} else {
		printf("%d\n%d\n", sum, min);
	}
	return 0;
}
