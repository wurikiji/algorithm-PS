#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(void){ 
    int n;
    long long arr[128];
    scanf("%d", &n);
    for(int i = 0 ;i < n;i++) {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n);

    vector<long long> v;
    long long diff = arr[n-1] - arr[0];
    for(int i = 2 ;i < sqrt(diff) + 1;i++) {
        if (diff % i == 0) {
            v.push_back(i);
            if (i != diff / i) {
                v.push_back(diff/i);
            }
        }
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = 0 ;i < v.size();i++) {
        long long mod = arr[0] % v[i];
        for(int j = 1 ;j < n;j++) {
            if (arr[j] % v[i] != mod) {
                mod = -1;
                break;
            }
        }
        if (mod != -1) {
            if (cnt) printf(" ");
            printf("%lld", v[i]);
            cnt++;
        }
    }
    printf("\n");
    return 0;
}