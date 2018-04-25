#include <cstdio>
#include <cmath>

int main(void) {
	bool chk[1010101] = {0,};
	int arr[356000] = {0,};
	chk[1] = true;
	for(int i = 2;i < sqrt(1000000) + 1;i++) {
		if (chk[i] == false) {
			for(int j = 2;j * i <= 1000000;j++) {
				chk[j*i] = true;
			}
		}
	}
	for(int i = 1; i <= 356000;i++) {
		arr[i] += arr[i-1];
		if (chk[i] == false) {
			arr[i]++;
		}
	}
	int n;
	while(1) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", arr[2*n] - arr[n]);
	}
	return 0;
}
