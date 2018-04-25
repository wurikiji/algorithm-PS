#include <cstdio>
#include <queue>

using namespace std;

int min(int x, int y) {
	return x> y? y: x;
}
int main(void){ 
	int n, m;
	scanf("%d %d", &n, &m);

	queue<int> q;
	for(int  i = 1;i <= n;i++) {
		q.push(i);
	}
	
	int dap = 0;
	for(int i = 0 ;i < m;i++) {
		int tmp;
		scanf("%d", &tmp);
		int cnt = 0;
		while(!q.empty() && q.front() != tmp) {
			q.push(q.front());
			q.pop();
			cnt++;
		}
		dap += min(cnt, q.size() - cnt);
		q.pop();
	}
	printf("%d\n", dap);
		
	return 0;
}
