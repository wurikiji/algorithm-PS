#include <cstdio>

bool isDeungCha(int n) {
	int pre = 0;
	if (n < 100)
		return true;

	pre = (n%10) - ((n/10)%10);

	n /= 10;
	while(n / 10) {
		if (pre != (n%10) - ((n/10)%10))
			return false;
		n /= 10;
	}
	return true;
}
int main(void){ 
	int n;
	scanf("%d", &n);
	int dap = 0;
	for(int i = 1; i<=n;i++) {
		if (isDeungCha(i)) 
			dap++;
	}
	printf("%d\n",dap);
	return 0;
}
