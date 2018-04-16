#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    vector<int> v;
    scanf("%d", &n);
    while(n--) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    double dap = 0.0;
    for(int i = 0 ;i < v.size();i++) {
        dap += (((double)v[i]/v[v.size()-1]) * 100);
    }
    printf("%2.2lf", dap/v.size());
    return 0;
}
