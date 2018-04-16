#include <cstdio>
#include <cstring>

int main(void){
	char buf[1000010];
	int arr[32];
	int diff = 'A' - 'a';
	if ( scanf("%s", buf) == EOF ) {
		printf("?\n");
		return 0;
	}
	memset(arr, 0, sizeof(arr));

	int dap = 0;
	int len = strlen(buf);
	for(int i = 0 ;i < len ;i++) {
		if (buf[i] >= 'A' && buf[i] <='Z') 
			buf[i] -= diff;
		dap = buf[i]-'a';
		arr[dap]++;
	}

	int cnt = 1;

	for(int i = 0; i < 'z'-'a'+1;i++) {
		if (i != dap && arr[dap] == arr[i]) {
			cnt++;
		} else if (arr[dap] < arr[i]) {
			dap = i;
			cnt = 1;
		}
	}

	if (cnt == 1 && arr[dap] != 0) {
		printf("%c\n", 'A' + dap);
	} else {
		printf("?\n");
	}
	return 0;
}
