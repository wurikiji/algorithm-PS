#include <vector>
#include <cstdio>
#include <set>

using namespace std;

struct dap {
	long long a;
	long long m;
	dap(long long _a, long long _m)
		: a(_a), m(_m) {}
	bool operator<(const struct dap & other) const
	{
		return (double)a / m + 1e-9 < (double)other.a / other.m ;
	}
};
int main(void) {
	long long n,b;
	long long c = 1;
	while(scanf("%lld %lld", &b, &n) && b!=0 && n != 0) {
		set<struct dap> ret;
		ret.insert(dap(0,2*n));
		long long m = 1;
		while (2 * b * m > b * m * m / n) {
			if ( (b * m * m) % n != 0) {
				m++;
				continue;
			}
			long long a = (2 * b * m - b * m * m / n) ;
			if (a % n == 0) {
				ret.insert(dap(a / n, m));
			}
			m++;
		}
		bool first = true;
		for(auto p : ret) {
			if (p.a != b && p.m != n) {
				if (!first)
					printf(" ");
				first = false;
				printf("%lld/%lld", 
						p.a, p.m);
			}
		}
		printf("\n");
	}
	return 0;
}
