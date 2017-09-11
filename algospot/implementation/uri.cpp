#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(void){
  int c;
  cin>>c;

  map< string, char> m;
  m[string("%20")] = ' ';
  m[string("%21")] = '!';
  m[string("%24")] = '$';
  m[string("%25")] = '%';
  m[string("%28")] = '(';
  m[string("%29")] = ')';
  m[string("%2a")] = '*';

  while(c--)
  {
    string s;
    cin>>s;
    string dap="";

    int prev = 0;
    for(int i = 0 ;i < s.length();)
    {
      if( (s[i] == '%') && (m.end() != m.find(s.substr(i,3))))
      {
        dap += s.substr(prev, i-prev);
        i += 2;
        s[i] = m[s.substr(i-2,3)];
        prev = i;
      }
      i++;
    }
    dap += s.substr(prev);
    cout<<dap<<endl;
  }
  return 0;
}
