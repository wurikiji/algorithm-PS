#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){ 
    int n;
    scanf("%d", &n);
    long long sum = 0;
    vector<long long> v; 
    for(int i = 0 ;i < n;i++) {
        long long t;
        scanf("%lld", &t);
        v.push_back(t);
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0 ;i < v.size();i++) {
        v[i] -= i;
        if (v[i] > 0) sum += v[i];
    }
    printf("%lld\n", sum);
    return 0;
}