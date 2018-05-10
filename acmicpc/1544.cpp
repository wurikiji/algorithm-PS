#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void){ 
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0 ;i < n;i++) {
        string str;
        cin >> str;
        int j = 0;
        for(j = 0 ;j < v.size();j++) {
            if (v[j].size() / 2 == str.size() && v[j].find(str) != string::npos){
                // 길이가 같고, 존재함. 
                break;
            }
        }
        if (j == v.size()) 
            v.push_back(str + str);
    }
    cout << v.size() << endl;
    return 0;
}