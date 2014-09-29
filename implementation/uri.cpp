#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(void){
  int c;
  cin>>c;

  map< string, int> m;
  m[string("%20")] = 2;
  m[string("%21")] = 2;
  m[string("%24")] = 2;
  m[string("%25")] = 2;
  m[string("%28")] = 2;
  m[string("%29")] = 2;
  m[string("%2a")] = 2;
  while(c--)
  {
    string s;
    cin>>s;

  }
  return 0;
}
