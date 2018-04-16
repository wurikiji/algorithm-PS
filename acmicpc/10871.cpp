#include <cstdio>
#include <vector>

using namespace std;
int main(void){
    int n,x;
    
    scanf("%d %d", &n, &x);
    int cnt = 0;
    while(n--) {
        int temp;
        scanf("%d", &temp);
        if (cnt)
            printf(" ");
        if (temp < x) {
            printf("%d", temp);
            cnt++;
        }
    }
    return 0;
}
