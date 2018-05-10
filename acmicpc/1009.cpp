#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

string operator*(const string& a, const int& b) {
    string ret = "";
    for(int i = 0 ;i < b;i++) {
        ret += a;
    }
    return ret;
}

int main(void){ 
    int t, a, b;
    string arr[10] = {"0",};
    for(int i = 1; i < 10;i++) {
        string rep = "";
        t = 1;
        while (rep.length() == 0 
            || rep.substr(0, rep.length()/2) * 2 != rep) {
            t *= i;
            t %= 10;
            rep += (t + '0');
        }
        arr[i] = rep.substr(0,rep.length()/2);
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        int dap = arr[a % 10][((b-1) % arr[a % 10].length())];
        printf("%d\n", (dap=='0'?10:dap - '0'));
    }
    return 0;
}