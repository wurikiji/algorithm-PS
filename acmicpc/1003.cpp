<<<<<<< HEAD
#include <cstdio>
int zero, one;

int fibonacci(int n) {
    if (n==0) {
        zero++;
        return 0;
    } else if (n == 1) {
        one++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci (n-2);
    }
}

int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        zero = 0;
        one = 0;
        fibonacci(n);
        printf("%d %d\n", zero, one);
    }
    return 0;
}
=======
#include <cstdio>

int main(void) {
	long long arr[64][4];
	int t;
	scanf("%d", &t);
	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;

	for (int i = 2; i <= 40;i++) {
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%lld %lld\n", arr[n][0], arr[n][1]);
	}
	return 0;
}
>>>>>>> cc2c68474e269f21d71e9ff41ce05f3e6fc1edde
