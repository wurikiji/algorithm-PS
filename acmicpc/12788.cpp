#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
	int n,m,k;
	int arr[1024];
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0 ;i <n ;i++) { 
		scanf("%d", arr + i);
	}

	sort(arr, arr + n );
	int sum = 0;
	int i ;
	for(i = 0 ;i < n && sum < m * k;i++) {
		sum += arr[n - i - 1];
	}
	if (sum < m * k) {
		printf("STRESS\n");
	} else {
		printf("%d\n", i);
	}

	return 0;
}
