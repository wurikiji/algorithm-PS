#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(void){ 
    int n;
    stack<int> st;
    bool pushed[101010] = {0};
    int top = -1;
    vector<char> vc;
    st.push(0);
    scanf("%d", &n);
    while(n--) {
        int tmp;
        scanf("%d", &tmp);

        for(int i = st.top() + 1;i <= tmp;i++) {
            if (!pushed[i]) {
                st.push(i);
                vc.push_back('+');
                pushed[i] = true;
            }
        }
        if (st.top() != tmp) {
            printf("NO\n");
            return 0;
        }
        st.pop();
        vc.push_back('-');
    }
    for(auto c: vc) {
        printf("%c\n", c);
    }
    return 0;
}