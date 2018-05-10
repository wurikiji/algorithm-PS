#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){ 
	long long arr[1024];
	int n;
	scanf("%d", &n);
	for(int i = 0 ;i < n;i++) {
		scanf("%lld", arr + i);
	}
	sort(arr, arr + n);
	long long sum = arr[0];
	for(int i = 1 ;i <n;i++) {
		arr[i] += arr[i-1];
		sum += arr[i];
	}
	printf("%lld\n", sum);
	return 0;
}
