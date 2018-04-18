#include <cstdio>
#include <cmath>

int main(void) {
	int n;
	scanf("%d", &n);

	int x = sqrt(2 * n);
	int start = x * (x-1) /2;

	if (x * (x + 1) / 2 < n) {
		x++;
		start = x * ( x - 1) /2;
	}

	if (x % 2 == 1) {
		printf("%d/%d\n", (x - (n - start) + 1), (n - start));
	} else {
		printf("%d/%d\n",  (n - start), (x - (n - start) + 1));
	}
	return 0;
}
