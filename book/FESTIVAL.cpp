/* simple problem */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>


using namespace std;


double min(double a, double b)
{
  return a < b - 1e-7 ? a: b;
}
int main(void)
{
  int c;
  scanf("%d", &c);

  while(c--)
  {
    int n, l;
    double dap=(int)0x7fffffff;
    double cost[1001][1001];
    memset(cost,0,sizeof(cost));
    scanf("%d %d", &n, &l);
  
    for(int i = 1 ;i<= n;i++)
    {
      scanf("%lf", &cost[i][1]);
      for(int j = i-1;j > 0 ;j--)
      {
        cost[j][i - j + 1] = cost[j][i-j] + cost[i][1];
        if( i - j + 1 >= l )
        {
          dap = min(dap, cost[j][i-j + 1]/(i - j + 1));
        }
      }
      if( 1 >= l )
        dap = min(dap, cost[i][1]);
    }
    printf("%.8lf\n", dap);

  }
  return 0;
}
