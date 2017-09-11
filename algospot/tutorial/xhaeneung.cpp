#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define s(a) string(a)


int oper(int a, int b, string op)
{
  if( op == "*" ) return a * b;
  if( op == "+" ) return a + b;
  if( op == "-" ) return a - b;
}


int main(void){
  int n;
  cin>>n;
  map<string, int> m;
  map<int, string> rm;
  char ss[11][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

  for(int i = 0 ;i < 11;i++)
  {
    m[ s(ss[i]) ] = i;
    rm[i] = s(ss[i]);
    sort(rm[i].begin(),rm[i].end());
  }

  while(n--)
  {
    string a,b,dap;
    string t1,t2;
    cin >> a>> t1>>b>>t2>>dap;
      
    int t = oper(m[a],m[b],t1);
    if( t < 0 || t > 10 ) cout<<"No"<<endl;
    else
    {
      sort(dap.begin(),dap.end());
      cout << ( rm[t] == dap ? "Yes":"No") <<endl;
    }
  }
  return 0;
}
