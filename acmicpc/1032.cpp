#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string str;
    string dap(64, ' ');
    for(int i = 0 ;i < n;i++){
        cin >> str;
        for(int j = 0 ;j < str.size();j++) {
            if (dap[j] == ' '){
                dap[j] = str[j];
            } else if (dap[j] != str[j]) {
                dap[j] = '?';
            }
        }
    }
    for(int i = 0 ;dap[i] != ' ' ;i++) {
        cout << dap[i];
    }
    cout << endl;
    return 0;
}