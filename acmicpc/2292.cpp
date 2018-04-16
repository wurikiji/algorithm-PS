#include <cstdio>

int main(void) {
	long long n;
	scanf("%lld", &n);
	long long start = 1;
	for(int i = 0 ; start < n;i++) {
		long long next = start + 6 * (i+1);
		if (start + 1 <= n && n <= next) {
			printf("%d\n", i + 2);
			return 0;
		}
		start = next;
	}
	printf("1\n");
	return 0;
}
