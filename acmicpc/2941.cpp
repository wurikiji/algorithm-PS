#include <cstdio>
#include <cstring>

int main(void){ 
	char buf[128];
	scanf("%s", buf);
	int len = strlen(buf);
	if (len == 0)
		printf("0\n");
	else if (len == 1) 
		printf("1\n");
	else {
		int cnt = 0;
		char dic[16][8] = {
			"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=", 
		};
		for(int i = 0 ;i < len;) {
			for(int j = 0 ;j < 8;j++) {
				if (0 == strncmp(buf + i, dic[j], strlen(dic[j]))) {
					i += (strlen(dic[j]) - 1);
					break;
				}
			}
			cnt++;
			i++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
