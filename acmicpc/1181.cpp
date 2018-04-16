#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a.compare(b) < 0;
    } else {
        return a.size() < b.size();
    }
}
int main(void){ 
    int n;

    scanf("%d", &n);
    set<string, bool(*)(string,string)> str(cmp);
    // 다른 해답
    // set <pair<int, string>> 을 통해서
    // strlen(string), string 쌍으로 저장을 하면
    // 자동으로 길이 순 정렬 + 사전 순 정렬 + unique가 완성이 된다. 
    while(n--) {
        string tmp;
        cin >> tmp;
        str.insert(tmp);
    }
    for ( auto &iter : str) {
        cout << iter << endl;
    }

    return 0;
}