#include <cstdio>
#include <cmath>
using namespace std;
int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        long long dist = pow((x1-x2), 2) + pow(y1-y2,2);
        long long rdist = pow(r1 + r2, 2);
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            // 같은 원
            printf("-1\n");
        } else if (dist > rdist){
            // 인접하지 않음. 
            printf("0\n");
        } else if (dist == rdist) {
            // 한점에서 만남. 
            printf("1\n");
        } else if ( (r1-r2) * (r1-r2) == dist){
            // 원안에서 한점에서 만남.
            printf("1\n");
        } else if (dist < (r1 - r2) * (r1-r2)){
            // 한 원이 다른 원의 안에 존재.
            printf("0\n");
        } else {
            // 그 외의 경우.
            printf("2\n");
        }

    }
    return 0;
}