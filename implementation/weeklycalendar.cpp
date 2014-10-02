#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int dToi(string s)
{
  if( s[0] == 'S' )
  {
    if( s[1] == 'u' ) return 0;
    return 6;
  }
  if( s[0] == 'T' ) 
  {
    if( s[1] == 'u') return 2;
    return 4;
  }
  if( s[0] == 'M') return 1;
  if( s[0] == 'W') return 3;
  return 5;
    
}
int main(void){
  int t;
  int dal[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  cin >> t;

  while(t--)
  {
    int m,d;
    string day;
    string apdap, duidap;

    cin >> m >> d >> day;
    int numDay = dToi(day);

    int pd = d-1;
    for(int i = 0 ;i < numDay;i++)
    {
      if( pd == 0 )  pd = dal[ (m - 1 == 0)? 12:m-1 ] ;
      apdap = std::to_string(pd) + " " + apdap;
      pd--;
    }
    pd = d + 1;
    for(int i = numDay+1; i < 7;i++)
    {
      if( pd == dal[m] + 1  ) pd = 1;
      duidap += " " + to_string(pd);
      pd++;
    }
    cout << apdap<< d << duidap<<endl;
  }
  return 0;
}

