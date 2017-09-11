#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;


vector<int> v;

bool chk[500010];

bool canMake(int i, int n)
{
  if( n < 0 ) return false;
  if( n == 0 ) return true;
  if( n != 0 && i == 0 ) return false;
  if( chk[n] ) return true;
  if( i == 1 ) 
  {
    for(int j = 0 ;j < i ;j++)
      if( v[j] == n ){
        chk[n] = true;
        return true;
      }
    return false;
  }
  if(canMake(i-1, n-v[i-1]) || canMake(i-1,n))
  {
    chk[n] = true;
    return true;
  }
  return false;
}
int main(void){
  int c;
  cin >> c;


  while(c--)
  {
    int n;
    cin >> n;
    if( n == 1 || n == 2  || ( n % 2 == 1) ) {
      cout <<"not weird"<<endl;
      continue;
    }

    bool w = false;

    int sum = 0 ;
    int i;
    v.clear();

    memset(chk, 0, sizeof(chk));
    for(i = 1; i * i < n ;i++)
    {
      if( (n % i) == 0 )
      {
        sum += i ;
        v.push_back(i);
        if( i != 1 )
        {
          sum += ( n / i );
          v.push_back(n/i);
        }
      }
    }
    if( i * i == n ){
      sum += i;
      v.push_back(i);
    }
    sort(v.begin(), v.end());
    
    if( (sum > n) && !canMake(v.size(),n))
    {
      w = true;
    }
    if( w ) cout<<"weird"<<endl;
    else cout<<"not weird"<<endl;
  }
  return 0;
}
