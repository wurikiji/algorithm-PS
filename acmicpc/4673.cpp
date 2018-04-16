#include <cstdio>
#include <cstring>

int main(void) {
	bool self[20010];
	memset(self, 1, sizeof(self));

	self[1] = true;
	for(int i = 1;i <= 10000;i++) {
		int constructor = i;
		while( constructor < 10000) {
			int next = constructor;
			while (constructor) {
				next += (constructor %10);
				constructor /= 10;
			}
			self [next] = false;
			constructor = next;
		}
		if (self[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}
