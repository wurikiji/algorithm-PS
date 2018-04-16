#include <cstdio>


int main(void){ 
	int c;
	int n;
	int arr[1010];
	scanf("%d", &c);
	while(c--) {
		scanf("%d", &n);
		double sum = 0.0;
		for(int i = 0 ;i < n;i++) {
			scanf("%d", arr + i);
			sum += arr[i];
		}
		sum /= n;
		int good = 0;
		for(int i = 0 ;i < n;i++) {
			if (arr[i] - sum > 1e-9) {
				good++;
			}
		}
		printf("%.3lf%%\n", ((double)good)/n * 100);
	}
	return 0;
}
