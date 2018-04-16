#include <cstdio>

int main(void){
	long long a,b,c;
	int arr[10];
	scanf("%lld", &a);
	scanf("%lld", &b);
	scanf("%lld", &c);
	long long mul = a * b * c;

	for(int i = 0 ;i < 10;i++)
		arr[i] = 0;

	while(mul) {
		arr[(mul%10)]++;
		mul = mul/10;
	}

	for (int i = 0 ;i < 10;i++) 
		printf("%d\n", arr[i]);
	return 0;
}
	
