#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>



int main(void){ 
    int r;
    scanf("%d", &r);
    printf("%.6lf\n", M_PI * pow(r, 2));
    printf("%.6lf\n", pow(r * 2,2) / 2);
    return 0;
}