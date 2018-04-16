#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<string> dap[16];

void createDap(int x) {
    if (dap[x].size() != 0)
        return;

    createDap(x-1);

    int space = 3 * pow(2, (x-1));
    string dummySpace((size_t)space, ' ');
    int xlen = dap[x-1].size();

    dap[x].resize(xlen * 2);

    for(int i = 0 ;i < xlen;i++) {
        dap[x][i] = dummySpace + dap[x-1][i] + dummySpace;
        string temp( (size_t)dap[x-1][i].size() * 2 + 1, ' ');
        for(int j = 0;j <dap[x-1][i].size();j++) {
            temp[j] = dap[x-1][i][j];
            temp[j+space * 2] = dap[x-1][i][j];
        }
        dap[x][i + xlen] = temp;
    }
}

int main(void){ 
    int n;
    int k; 
    scanf("%d", &n); 
    k = n / 3;
    k = log2(k);
    dap[0].push_back("  *  ");
    dap[0].push_back(" * * ");
    dap[0].push_back("*****");
    createDap(k);
    for(int i = 0 ;i < dap[k].size();i++) {
        printf("%s\n", dap[k][i].c_str());
    }
    return 0;
}