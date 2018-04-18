#include <cstdio>
#include <cstdlib>
// #include <numeric>

long long gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main(void){ 
    int t;
    scanf("%d", &t);
    while(t--) {
        int m, n, x, y;

        scanf("%d %d %d %d", &m, &n, &x, &y);
        /*
            a = m * w + x;
            a = n * z + y;
            
            w, z <= 40,000
            다 돌아도 됨. 
        */
        
        if (x == y) {
            printf("%d\n", x);
        } else if (m == n) {
            printf("-1\n");
        } else {
			long long mLcm = lcm(m, n); // 멸망의 날 
			if (m > n){ 
				swap (m, n);
				swap (x, y);
			}
			long long mult = mLcm / m;
			long long i;
			for(i = 0 ;i <= mult;i++ ) {
				if (((x + i * m) % n) == (y %n))
					break;
			}
			if (i <= mult) {
				printf("%lld\n", x + i * m);
			} else {
				printf("-1\n");
			}
		}
    }
    return 0;
}
