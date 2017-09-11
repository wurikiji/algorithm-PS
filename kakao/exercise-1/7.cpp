#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<string> strs, string t)
{
    int len = t.size();
    int sz = strs.size();
    int dap[20010];
    memset(dap, 0xff, sizeof(dap));
    dap[len] = 0;
    for (int i = len-1;i>=0;i--) 
    {
        for (int j = 0;j < sz;j++)
        {
            string str = strs[j];
            int k;
            int slen = str.size();
            for (k = 0; k < slen && i + k < len; k++)
            {
                if (str[k] != t[i+k]) {
                    break;
                }
            }
            //if (str == t.substr(i, str.size()))
            if (k == slen)
            {
                if (dap[i + slen] >= 0){
                    if (dap[i] < 0)
                        dap[i] = dap[i+slen] + 1;
                    else
                        dap[i] = min(dap[i], dap[i+slen] + 1);
                } 
            }
        }
    }
    return dap[0];
}
