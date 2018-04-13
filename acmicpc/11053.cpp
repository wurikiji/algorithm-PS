#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void){ 
	int n;
	int arr[1010];
	int dap[1010];
	scanf("%d", &n);
	int ret = 0;
	for(int i = 0;i < n;i++) {
		int t;
		scanf("%d", &t);
		arr[i] = t;
		dap[i] = 1;
		if (i) {
			for (int j = 0 ;j <i; j++) {
				if (arr[i] > arr[j]) {
					dap[i] = max(dap[i], dap[j] + 1);
				}
			}
		}
		ret = max(ret, dap[i]);
	}
	printf("%d\n", ret);
	return 0;
}
