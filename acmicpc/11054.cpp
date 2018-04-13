#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int dap = 0;
	int arr[1010];
	int tmp[1010][2];
	scanf("%d", &n);
	for (int i = 0 ;i < n;i++) {
		int t;
		scanf("%d", &t);
		arr[i] = t;
		tmp[i][0] = 1;
		tmp[i][1] = 1;
		if (i) {
			for(int j = 0 ;j < i;j++) {
				if (arr[j] < arr[i]) {
					tmp[i][0] = max(tmp[i][0], tmp[j][0] + 1);
				} else if (arr[j] > arr[i]) {
					tmp[i][1] = max(tmp[i][1], max(tmp[j][0] + 1, tmp[j][1] + 1));
				}
			}
		}
		dap = max(dap, max(tmp[i][0], tmp[i][1]));
	}
	printf("%d\n", dap);
	return 0;
}
