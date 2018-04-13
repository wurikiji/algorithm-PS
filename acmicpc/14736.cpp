#include <cstdio>

int main(void){
	int n, k, a;
	int t[1001], s[1001];
	int dap = 0x7fffffff;
	scanf("%d %d %d", &n, &k, &a);

	for(int i = 0 ;i < n;i++) {
		scanf("%d %d", &t[i], &s[i]);
		int kk = k;
		int j = 0, h = 0;
		int d = 0;
		while (kk > 0) {
			if (j < t[i]) {
				kk -= a;
				j++;
			} else if (h < s[i]) {
				h++;
			} else {
				j = 1; h = 0;
				kk -= a;
			}
			d++;
		}
		if (dap > d)
			dap = d;
	}
	printf("%d\n", dap);
	return 0;
}
