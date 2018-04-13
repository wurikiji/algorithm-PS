#include <cstdio>
#include <cstring>
#include <string>


int main(void) {
	int n;
	int arr[1000010];
	int b,c;
	long long dap = 0;
	scanf("%d", &n);
	for(int i = 0 ;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &b, &c);
	for(int i = 0 ;i < n;i++) {
		dap += (1 + ((arr[i] - b > 0)? (arr[i]-b+c-1)/c:0));
	}
	printf("%lld\n", dap);

	return 0;
}
