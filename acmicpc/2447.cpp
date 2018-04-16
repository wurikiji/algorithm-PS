#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<string> dap[16];

void createDap(int x) {
    if (dap[x].size())
        return;
    int sz = pow(3,x);
    int small = pow(3, x-1);
    string temp(small, ' ');

    createDap(x-1);

    dap[x].resize(sz);

    for(int i = 0 ;i < sz;i++) {
        int sIdx = i % small;
        if (small <= i && i < small *2) {
            dap[x][i] = dap[x-1][sIdx] + temp + dap[x-1][sIdx];
        } else {
            dap[x][i] = dap[x-1][sIdx] + dap[x-1][sIdx] + dap[x-1][sIdx];
        }
    }
}
int main(void){ 
    int n;
    scanf("%d", &n);
    int k = log10(n + 1)/log10(3);

    dap[0].push_back("*");
    createDap(k);

    for(int i = 0 ;i < dap[k].size();i++) {
        printf("%s\n", dap[k][i].c_str());
    }
    return 0;
}