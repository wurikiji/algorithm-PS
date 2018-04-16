#include <cstdio>

int main(void) {
	int order = -1; // 0 a, 1 d, 2 m
	for(int i = 0 ;i < 8;i++) {
		int n;
		scanf("%d", &n);
		if (order == -1){
			if (i+1 == n) {
				order = 0;
			} else if (8 == n) {
				order = 1;
			} else {
				printf("mixed\n");
				return 0;
			}
		} else if (order == 0) {
			if (i+1 != n) {
				printf("mixed\n");
				return 0;
			}
		} else if (order == 1) {
			if (n != 8-i) {
				printf("mixed\n");
				return 0;
			}
		} 	
	}
	if (order == 0) {
		printf("ascending\n");
	} else {
		printf("descending\n");
	}
	return 0;
}
