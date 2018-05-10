#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){ 
    string str;
    cin >> str;
    string two = str;
    reverse(two.begin(), two.end());
    if (str == two) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}