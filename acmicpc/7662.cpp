#include <cstdio>
#include <map>

using namespace std;

bool cmp(int a, int b){ 
	return a > b;
}
int main(void){
	int t,n;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		map<int, int> pq;
		while(n--) {
			char op[16];
			int num;
			scanf("%s %d", op, &num);
			if (op[0] == 'I') {
				if (pq.find(num) != pq.end() && pq[num] != 0) {
					pq[num]++;
				} else { 
					pq[num] = 1;
				}
			} else if (op[0] == 'D') {
				if (!pq.empty()) {
					if (num == -1) {
						auto it = pq.begin();
						if (it->second == 1) {
							pq.erase(it);
						} else {
							it->second--;
						}
					} else {
						auto it = pq.end();
						it--;
						if (it->second == 1) {
							pq.erase(it);
						} else {
							it->second--;
						}
					}
				}
			}
		}
		if (pq.empty()) {
			printf("EMPTY\n");
		} else {
			auto end = pq.end();
			auto begin = pq.begin();
			end--;
			printf("%d %d\n", end->first, begin->first);
		}
	}
	return 0;
}
