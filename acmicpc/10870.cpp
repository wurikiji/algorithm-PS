
#include <cstdio>

int main(void){
	int arr[32] = {0,1,1};

	for(int i = 2;i < 30;i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", arr[n]);
	return 0;
}
