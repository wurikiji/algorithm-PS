#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

#include <map>
using namespace std;

vector<int> q;

void push() {
	int n;
	scanf("%d", &n);
	q.push_back(n);
}
void pop() {
	if (!q.empty()) {
		printf("%d\n", q[0]);
		q.erase(q.begin());
	} else {
		printf("-1\n");
	}
}
void size() {
	printf("%zu\n", q.size());
}
void empty() {
	if (q.empty()) {
		printf("1\n");
	} else {
		printf("0\n");
	}
}
void front() {
	if (q.empty()) {
		printf("-1\n");
	} else {
		printf("%d\n", q[0]);
	}
}
void back() {
	if (q.empty()) {
		printf("-1\n");
	} else {
		printf("%d\n", q[q.size()-1]);
	}
}

typedef void (*VoidFunction)(void);
map<string, VoidFunction> func;

int main(void){ 
	int n;
	scanf("%d", &n);
	func.emplace("push", push);
	func.emplace("pop", pop);
	func.emplace("size", size);
	func.emplace("empty", empty);
	func.emplace("front", front);
	func.emplace("back", back);
	while(n--) {
		string temp;
		cin >> temp;
		func[temp]();
	}
	return 0;
}
