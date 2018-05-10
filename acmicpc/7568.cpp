#include <cstdio>

int main(void){ 
	int n;
	int xrr[64];
	int yrr[64];
	int tier[64] = {0,};
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d %d", xrr + i, yrr +i);
	}
	for(int i = 0 ;i < n;i++) {
		for(int j = 0 ;j < n;j++) {
			if (i != j && xrr[i] < xrr[j] && yrr[i] < yrr[j]) {
				tier[i]++;
			}
		}
		if (i) printf(" ");
		printf("%d", tier[i] + 1);
	}
	return 0;
}
