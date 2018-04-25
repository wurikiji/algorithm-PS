#include <cstdio>
#include <cmath>



int main(void){ 
	int n;
	scanf("%d", &n);

	while(n--) {
		long long from, to;
		scanf("%lld %lld", &from, &to);
		long long dist = to - from;
		long long i = sqrt(4 * dist);
		if (i * i == 4 * dist) {
			i--;
		}
		printf("%lld\n", i);
	}

	return 0;
}
