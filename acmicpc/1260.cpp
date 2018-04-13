#include <cstring>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;
set<int> node[1010];

bool chk[1010];
bool first;
void dfs(int v) {
	chk[v] = true;
	if (!first) {
		printf(" ");
	}
	printf("%d", v);
	first=false;
	for (auto a : node[v]) {
		if (!chk[a])
			dfs(a);
	}
}

void bfs(int v) {
	queue<int> nxt;
	nxt.push(v);
	chk[v] = true;
	while(!nxt.empty()) {
		int nx = nxt.front();
		nxt.pop();
		if (!first)
			printf(" ");
		first = false;
		printf("%d", nx);
		for (auto a: node[nx]) {
			if (!chk[a]) {
				chk[a] = true;
				nxt.push(a);
			}
		}
	}
	printf("\n");
}

int main(void){ 
	int n,m,v;
	scanf("%d %d %d", &n, &m, &v);

	for(int i =0 ;i < m;i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		node[a].insert(b);
		node[b].insert(a);
	}

	first = true;
	memset(chk, 0, sizeof(chk));
	dfs(v);
	printf("\n");

	first = true;
	memset(chk, 0, sizeof(chk));
	bfs(v);
	return 0;
}
