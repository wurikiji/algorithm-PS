#include <cstdio>

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		int h, w, n;
		scanf("%d %d %d", &h , &w, &n);

		int ap = n % h;
		int dui = n / h;
		printf("%d%02d\n", ap == 0? h: ap, ap == 0? dui: dui + 1);
	}
	return 0;
}
