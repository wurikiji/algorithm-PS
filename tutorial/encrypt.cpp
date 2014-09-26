#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void){
  int t;
  scanf("%d", &t);

  while(t--)
  {
    string s;
    string dap1, dap2;
    cin >> s;
    for( int i = 0 ;i < (s.length()+1)/2;i++)
    {
      dap1 += s[i*2];
      if( i * 2 + 1 < s.length())
        dap2 += s[i*2+1];
    }
    cout << dap1<<dap2<<endl;
  }
  return 0;
}
