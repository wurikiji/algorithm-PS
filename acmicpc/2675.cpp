#include <cstdio>
#include <cstring>
int main(void){
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		char buf[1024];
		scanf("%d %s", &n, buf);
		for(int i = 0 ;i < strlen(buf);i++) {
			for (int j = 0 ;j < n;j++) {
				printf("%c", buf[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
