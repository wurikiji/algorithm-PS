#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int> > v) {
    //vector< vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
    int x[4],y[4];
    vector<int> ans;
    for (int i =0 ;i < v.size();i++)
    {
        x[i] = v[i][0]; y[i] = v[i][1];
    }
    for (int i =0 ;i < 3;i++) {
        int j;
        for (j = 0 ;j < 3;j++) {
            if (i != j && x[i] == x[j])
                break;
        }
        if (j == 3)
            ans.insert(ans.begin(),x[i]);
        
        for (j = 0 ;j < 3;j++) {
            if (i != j && y[i] == y[j])
                break;
        }
        if (j == 3)
            ans.push_back(y[i]);
    }
    
    return ans;
}
