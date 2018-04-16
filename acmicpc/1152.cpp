#include <cstdio>
#include <cstring>

int main(void) {
	char str[1010101];
	scanf("%[^\n^\r]s", str);

	int cnt = 0;
	for(int i = 0;i < strlen(str);i++) {
		if (i != 0 && str[i] == ' ' && i != strlen(str) -1)
			cnt++;
	}
	if (strlen(str) == 1 && str[0] == ' ')
		cnt = -1;
	if (strlen(str) == 0)
		cnt = -1;
	printf("%d\n", cnt + 1);
	return 0;
}

