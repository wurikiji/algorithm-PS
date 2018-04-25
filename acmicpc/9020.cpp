#include <cstdio>
#include <cmath>

#define MAX_IDX (10101)
int main(void) {
	bool chk[MAX_IDX + 10] = {0,};
	chk[1] = true;
	for(int i = 2;i < sqrt(MAX_IDX) + 1;i++) {
		if (chk[i] == false) {
			for(int j = 2;j * i <= MAX_IDX;j++) {
				chk[j*i] = true;
			}
		}
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int half = n / 2;
		for(int i = half ;i < n;i++) {
			if (chk[i] == false && chk[n-i] == false) {
				printf("%d %d\n", n-i, i);
				break;
			}
		}
	}
	return 0;
}
