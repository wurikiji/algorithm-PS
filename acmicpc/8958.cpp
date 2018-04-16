#include <cstdio>
#include <cstring>

int main(void){ 
	int n;
	scanf("%d", &n);
	char buf[100];
	int jumsoo[100];
	while(n--) {
		scanf("%s", buf);
		int sz = strlen(buf);
		int dap = 0;
		for(int i = 0 ;i < sz;i++) {
			jumsoo[i] = 0;
			if (buf[i] == 'O') {
				jumsoo[i] = i == 0?1:jumsoo[i-1] + 1;
			}
			dap += jumsoo[i];
		}
		printf("%d\n", dap);
	}
	return 0;
}
