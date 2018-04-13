#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define VERY_BIG 0x0fffffff
int main(void){
    int n;
    scanf("%d", &n);
    int arr[5050][2];

	for(int i = 0 ;i < 5050;i++) {
		for(int j = 0 ;j < 2;j++) {
			arr[i][j] = VERY_BIG;
		}
	}
	arr[3][0] = 1; // 3kg
	arr[5][1] = 1; // 5kg

    for(int i=6;i<=n;i++) {
		arr[i][0] = min(arr[i-3][0] + 1, arr[i-3][1] + 1);
		arr[i][1] = min(arr[i-5][0] + 1, arr[i-5][1] + 1);
    }

	int dap = min(arr[n][0], arr[n][1]);
	if (dap >= VERY_BIG) {
		printf("-1\n");
	} else {
		printf("%d\n", dap);
	}
    return 0;
}
