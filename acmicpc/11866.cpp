#include <cstdio>
#include <queue>

using namespace std;

int main(void){ 
	queue<int> q;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1 ;i <= n; i++) {
		q.push(i);
	}
	printf("<");
	for(int i = 0 ;!q.empty();i++) {
		if (i) 
			printf(", ");
		for(int j= 0 ;j < m-1;j++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d", q.front());
		q.pop();
	}
	printf(">\n");
	return 0;
}
