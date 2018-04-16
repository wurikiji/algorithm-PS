#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void){ 
	string str;
	cin >> str;
	
	int len = str.length();
	
	stack<char> st;

	stack<int> dap;
	if (len == 0 || len == 2) {
		printf("0\n");
		return 0;
	}
	bool closed = false;
	for(int i = 0 ;i < len;i++) {
		if (str[i] == '(') {
			closed = false;
			dap.push(0);
			st.push(str[i]);
		} else if (str[i] == '[') {
			closed = false;
			dap.push(0);
			st.push(str[i]);
		} else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				printf("0\n");
				return 0;
			}
			int top = 0;
			st.pop();

			while(dap.top() != 0) {
				top += dap.top();
				dap.pop();
			}
			dap.pop();

			if (closed) {
				top *= 3;
			} else {
				top += 3;
			}
			dap.push(top);
			closed = true;
		} else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				printf("0\n");
				return 0;
			}
			int top = 0;
			st.pop();
			while(dap.top() != 0) {
				top += dap.top();
				dap.pop();
			}
			dap.pop();
			if (closed) {
				top *= 2;
			} else {
				top += 2;
			}
			dap.push(top);
			closed = true;
		}
	}

	if (!st.empty()) {
		printf("0\n");
	} else {
		int sum = 0;
		while(!dap.empty()) {
			sum += dap.top();
			dap.pop();
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
