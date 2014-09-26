#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
  int c;
  scanf("%d",&c);
  while(c--)
  {
    int n,s;
    scanf("%d %d", &n,&s);
    vector<int> v;
    for(int i = 0;i < n;i++)
    {
      int temp;
      scanf("%d",&temp);
      v.push_back(temp);
    }
    int avg[101][101]={0,};
    sort(v.begin(), v.end());
    for(int i = 0 ;i<n;i++)
    {
      for(int j = i ;j < n;j++)
      {
        if( i==j){
          avg[i][j] = v[i];
          continue;
        }
        avg[i][j] = (avj[i][j-1]*(j-1-i+1) + v[j] )/(j-i+1);
      }
    }
  }
  return 0;
}
