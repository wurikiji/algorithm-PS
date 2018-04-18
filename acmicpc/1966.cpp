#include <queue>
#include <cstdio>

struct Doc {
	int prio;
	int idx;
	Doc(int _prio, int _idx) 
		:prio(_prio), idx(_idx){}
};

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		std::queue<Doc> pq;
		int n, idx;
		int arr[128];
		scanf("%d %d", &n, &idx);
		for(int i = 0 ;i < n;i++) {
			scanf("%d", arr + i);
			pq.emplace(arr[i], i);
		}
	}
	return 0;
}
