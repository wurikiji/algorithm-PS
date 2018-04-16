#include <cstdio>

int main(void){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int tmp = n;
	while(cnt == 0 || tmp != n) {
		cnt++;
		int pre = tmp;
		tmp = (tmp %10) + (tmp/10);
		tmp = (pre % 10) * 10 + (tmp % 10);
	}
	printf("%d\n", cnt);
	return 0;
}
