#include <cstdio>
#include <cstring>

int main(void){ 
	char buf[32];
	int arr[32] = {
		3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10,
	};
	scanf("%s", buf);
	int len = strlen(buf);
	int sum = 0;
	for(int i = 0 ;i < len;i++) {
		sum += arr[buf[i]-'A'];
	}
	printf("%d\n", sum);
	return 0;
}
