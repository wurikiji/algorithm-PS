#include<vector>
#include <cstring>
#include <cstdio>
using namespace std;

int dap[100001][4];
int get_dap_max(int i, int ex = -1) 
{
    int ret = 0;
    for (int j = 0 ;j < 4;j++) {
        if (j != ex && ret < dap[i][j]) {
            ret = dap[i][j];
        }
    }
    return ret;
}
int solution(vector<vector<int> > land)
{
	int answer = 0;
    for (int i = 0 ;i < 4;i++) {
        dap[0][i] = land[0][i];
    }
    for (int i = 1;i < land.size();i++) {
        for (int j = 0;j < 4;j++) {
            dap[i][j] = get_dap_max(i-1, j) + land[i][j];
        }
    }
	return get_dap_max(land.size()-1);
}
