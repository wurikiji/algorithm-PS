#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

long long cost[512000];
long long get[512000];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 0 ;i < n;i++) {
		scanf("%lld", &get[i]);
		if (i != 0) {
			get[i] += get[i-1];
		}
	}

	for(int i = 0 ;i < n;i++) {
		scanf("%lld", &cost[i]);
		if (i != 0) {
			cost[i] += cost[i-1];
		}
	}

	int start = 0, end = 1;
	int dap = 0;

	for(int i = 0 ;i < n;i++) {
		int cst = 0;
		int oil = 0;
		while (end != start) {
			if (end > start) {
				if (start == 0) {
					cst = cost[end-1];
					oil = get[end-1];
				} else {
					cst = cost[end-1] - cost[start-1];
					oil = get[end - 1] - get[start-1];
				}
			} else {
				if (end == 0) {
					cst = cost[n-1] - cost[start-1];
					oil = get[n-1] - get[start-1];
				} else {
					cst = cost[n-1] - cost[start-1] + cost[end];
					oil = get[n-1] - get[start-1] + get[end-1];
				}
			}

			printf("%d to %d: c %d, o %d\n",
					start, end, cst, oil);
			if (cst > oil) {
				/* fail */
				break;
			} else {
				/* success */
				end = (end + 1 + n) % n;
			}
		}
		if (end == start) {
			end = (end - 1 + n) % n;
			oil = oil - cst;
			if (end == 0) {
				cst = cost[end];
				oil += get[end];
			} else {
				cst = cost[end] - cost[end-1];
				oil += get[end] - get[end-1];
			}
			if (cst <= oil) {
				dap++;
				printf("%d to %d\n", 
						start, end);
				break;
			}
		}
		start = (start - 1 + n) % n;
	}

	printf("%d\n", dap);

	return 0;
}
