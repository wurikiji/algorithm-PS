#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int b;
	int n;
	string dap="";
	scanf("%d %d", &n, &b);
	while (n) {
		if (n%b < 10)
			dap += to_string(n%b);
		else
			dap += (char)('A'+(n%b)-10);
		n = n/b;
	}
	reverse(dap.begin(),dap.end());
	cout << dap <<endl;
	return 0;
}
