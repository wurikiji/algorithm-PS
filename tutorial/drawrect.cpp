#include <iostream>
#include <cstring>


using namespace std;

int main(void)
{
  int t;
  cin>>t;
  while(t--)
  {
    int x[3],y[3];
    int chkx[1001], chky[1001];
    memset(chkx,0,sizeof(chkx));
    memset(chky,0,sizeof(chky));
    for(int i = 0 ;i < 3;i++)
    {
      cin>>x[i]>>y[i];
      chkx[x[i]]++;
      chky[y[i]]++;
    }
    
    int dx,dy;
    for(int i = 0 ;i< 3;i++)
    {
      if( chkx[x[i]] != 2) dx = x[i];
      if( chky[y[i]] != 2) dy = y[i];
    }
    cout<<dx<<" "<<dy<<endl;

  }
  return 0;
}
