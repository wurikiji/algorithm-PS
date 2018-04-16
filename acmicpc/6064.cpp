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
        int m_diff = (m - n);
        int x_diff = (x - y);
        long long mLcm = lcm(m, n); // 멸망의 날 
        
        if (x_diff == 0) {
            printf("%d\n", x);
        } else if (m_diff == 0) {
            printf("-1\n");
        } else if (m_diff * x_diff > 0) {
            // 둘다 음수 혹은 둘다 양수
            if (m_diff < 0) {
                m_diff = -m_diff;
                x_diff = -x_diff;
            }
        } else if (m_diff < 0) {
            
        } else {

        }
    }
    return 0;
}