#include <cstdio>

int main(void){ 
	int n;
	scanf("%d", &n);
	int cnt = 0;
	while(n--) {
		int tmp; 
		scanf("%d", &tmp);
		if (tmp == 1) continue;
		for(int i = 2;i < tmp;i++) {
			if ( (tmp%i) == 0 ) {
				tmp = 0;
				break;
			}
		}
		if (tmp != 0) 
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
