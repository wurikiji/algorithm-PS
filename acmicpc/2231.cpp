#include <cstdio>
#include <cstring>

int getDeSum(int n) {
	int sum = n;
	while(n) {
		sum += (n%10);
		n /= 10;
	}
	return sum;
}
int main(void) {
	char buf[32];
	scanf("%s", buf);

	int len = strlen(buf);
	int n;
	sscanf(buf, "%d", &n);
	for (int i = n - 9 * len - 1 ;i <= n;i++) {
		if (i < 0) i = 0;
		if (getDeSum(i) == n) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
