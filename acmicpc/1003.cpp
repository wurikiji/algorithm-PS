#include <cstdio>

int main(void) {
	long long arr[64][4];
	int t;
	scanf("%d", &t);
	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;

	for (int i = 2; i <= 40;i++) {
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%lld %lld\n", arr[n][0], arr[n][1]);
	}
	return 0;
}
