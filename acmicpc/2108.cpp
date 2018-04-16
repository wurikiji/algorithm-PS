#include <cstdio>

int main(void){ 
    int n;
    scanf("%d", &n);
    int arr[8010] = { 0};

    for(int i = 0 ;i < n;i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp+4000]++;
    }
    long long sum = 0;
    int count = 0;
    int mid = 0;
    int maxCountIdx = 0;
    int minNum = -1;
    int maxNum = -1;
    bool second = false;
    for(int i = 0 ;i < 8010 ;i++) {
        if (arr[i]) {
            sum += (arr[i] * (i-4000));
            if (count < (n + 1)/2 && count + arr[i] >= n/2) {
                mid = i;
            }
            count += arr[i];
            if (arr[maxCountIdx] < arr[i]) {
                maxCountIdx = i;
                second = false;
            } else if (arr[maxCountIdx] == arr[i] && second == false) {
                maxCountIdx = i;
                second = true;
            }
            maxNum = i;
            if (minNum == -1) minNum = i;
        }
    }

    printf("%.0Lf\n%d\n%d\n%d\n", ((long double)sum)/n, mid -4000, maxCountIdx - 4000, maxNum - minNum );
    return 0;
}