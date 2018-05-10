#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
int main(void) {
	int n;
	int arr[16][16] = {{0},};
	scanf("%d", &n);
	n++;
	for(int i = 0 ;i < 10;i++) {
		arr[1][i] = 1;
	}
	for(int i = 2 ;i < 11;i++) {
		for(int j = 1 ;j < 10;j++) {
			if (j + 1 >= i) {
				arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
			}
		}
	}
	int sum = 0;
	int i;
	int j;
	for(i = 1 ;i < 11;i++) {
		for(j = 0 ;j <10;j++) {
			sum += arr[i][j];
			if (sum >= n) {
				printf("%d",j);
				if (j == 0) {
					j = 9;
				} else {
					j--;
				}
				i--; 
				while(i > 0) {
					while(j >= 0 && sum - arr[i][j] >= n) {
						sum -= arr[i][j];
						j--;
					}
					printf("%d", j);
					j--;
					i--;
				}
				printf("\n");
				return 0;
			} 
		}
	}
	if (sum < n) {
		printf("-1\n");
	} 
	return 0;
}
