#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1010][1010];
int didx[1010];
int max(int a, int b){
    return a > b? a : b;
}
int getLcsCount(const string &a, const string &b, int aidx, int bidx, int prev) {
    if (aidx < 0 || bidx < 0)
        return 0;
    
    if (dp[aidx][bidx] >= 0)
        return dp[aidx][bidx]; 
    if (a[aidx] == b[bidx]) {
        dp[aidx][bidx] = getLcsCount(a, b, aidx - 1, bidx - 1, aidx) + 1;
    } else {
        dp[aidx][bidx] = max(getLcsCount(a, b, aidx, bidx-1, prev), getLcsCount(a, b, aidx-1, bidx, prev));
    }
    return dp[aidx][bidx];
}

int main(void){ 
    string a, b;

    cin >> a >> b;
    int alen = a.length();
    int blen = b.length();

    memset(dp, -1, sizeof(dp));
    memset(didx, -1, sizeof(didx));
    printf("%d\n", getLcsCount(a, b, alen-1, blen-1, -1));
    int nxtLen = dp[alen-1][blen-1];
    string str = "";
    for(int i = alen -1 ; i >= 0;i--) {
        for(int j = blen -1; j >= 0;j--) {
            if (dp[i][j] == nxtLen && a[i] == b[j]) {
                str += a[i];
                nxtLen--;
                break;
            }
        }
    }
    reverse(str.begin(), str.end());
    printf("%s\n", str.c_str());
    return 0;
}