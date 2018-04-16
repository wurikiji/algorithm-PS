#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(void) {
    char buf[32];
    scanf("%s", buf);
    int dap = 1;
    int len = strlen(buf);
    bool closed = false;
    if (buf[0] == ')' || buf[0] == ']') {
        printf("0\n");
        return 0;
    }

    stack<char> op;
    op.push(buf[0]);
    for (int i = 1 ;i < len;i++) {
        if (buf[i] == ')') {
            if (op.top() != '(') {
                printf("0\n");
                return 0;
            }
            if (closed) {
                
            } else {

            }
            closed = true;
        } else if (buf[i] == ']') {
            if (op.top() != '[') {
                printf("0\n");
                return 0;
            }
            if (closed) {
                
            } else {

            }
            closed = true;
        } else {
            op.push(buf[i]);
            closed = false;
        }
    }
    if (op.empty()) {
        printf("%d\n", dap);
    } else {
        printf("0\n");
    }
    return 0;
}