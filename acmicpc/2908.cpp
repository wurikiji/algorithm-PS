#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main(void){ 
	int a,b;
	char buf1[128];
	char buf2[128];
	scanf("%s %s", buf1, buf2);
	reverse(buf1, buf1 + strlen(buf1));
	reverse(buf2, buf2 + strlen(buf2));
	sscanf(buf1, "%d", &a);
	sscanf(buf2, "%d", &b);
	if (a > b) {
		printf("%d\n", a);
	} else {
		printf("%d\n", b);
	}
	return 0;
}
