#include <cstring>
#include <cstdio>

bool isGroupWord(char *buf) {
	int len = strlen(buf);
	bool arr[32];
	memset(arr, 0,sizeof(arr));
	for(int i = 0 ;i < len;i++) {
		if (!arr[buf[i]-'a']) {
			arr[buf[i]-'a'] = true;
		} else if (buf[i-1] != buf[i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	int n;
	scanf("%d", &n);
	
	char buf[128];
	int dap = 0;
	for(int i = 0 ;i < n;i++) {
		scanf("%s", buf);
		if (isGroupWord(buf)) {
			dap++;
		}
	}
	printf("%d\n", dap);
	return 0;
}
