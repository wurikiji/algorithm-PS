
#include <cstdio>
#include <cstring>

#define MID (1024)
int main(void){ 
    int t;
    int cost[1024];
    int level[1024];
    scanf("%d", &t);
    while(t--) {
        int n, k;
        memset(level, 0, sizeof(level));
        scanf("%d %d", &n, &k);
        for(int i = 0 ;i < n;i++) {
            scanf("%d", cost + i);
        }
        for(int i = 0 ;i < k;i++) {
            int from, to;
            scanf("%d %d", &from, &to);
        }
        int w;
        scanf("%d", &w);
    }
    return 0;
}