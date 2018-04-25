#include <queue>
#include <cstdio>

using namespace std;

struct Doc {
	int idx;
	int prio;
	Doc(int _idx, int _prio) 
		: idx(_idx), prio(_prio) {}
	bool operator<(const struct Doc a) const {
		return prio < a.prio;
	}
};

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, idx;
		int arr[128];
		priority_queue<Doc> pq;
		queue<Doc> q;
		scanf("%d %d", &n, &idx);
		for(int i = 0 ;i < n;i++) {
			scanf("%d", arr + i);
			pq.emplace(i, arr[i]);
			q.emplace(i, arr[i]);
		}
		int cnt = 0;
		while(!q.empty()) {
			Doc maxPrio = pq.top();
			Doc curDoc = q.front();
			if (curDoc.prio == maxPrio.prio) {
				pq.pop();
				q.pop();
				cnt++;
				if (curDoc.idx == idx) {
					break;
				}
			} else {
				q.push(q.front());
				q.pop();
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
