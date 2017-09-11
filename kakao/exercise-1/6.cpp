#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int dap[100100][2];
vector<int> v;

int solve(int start, int end) {
    if (start == end) {
        dap[start][0] = 0;
        dap[start][1] = v[start];
        return v[start];
    } else if (start > end)
        return 0;
    
    if (dap[start][0] == 0) {
        dap[start][0] =
            solve(start + 1, end);
    }
    if (dap[start][1] == 0 ) {
        dap[start][1] = 
            solve(start + 2, end) + v[start];
    }
    return max(dap[start][0], dap[start][1]);
}
int solution(vector<int> s)
{
    int answer = 0;
    v = s;
    memset(dap,  0, sizeof(dap));
    answer = solve(1, s.size()-1);
    
    memset(dap, 0, sizeof(dap));
    answer = max(answer, s[0] + solve(2, s.size()-2)); 
    return answer;
}
