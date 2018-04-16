#include <cstdio>
#include <algorithm>
#include <cstring>

bool cmp(char a, char b) {
    return a > b;
}
int main(void){ 
    char buf[16];
    
    scanf("%s", buf);

    std::sort(buf, buf + strlen(buf), cmp);

    printf("%s\n", buf);

    return 0;
}