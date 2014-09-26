#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
  int n;
  scanf("%d",&n);
  int cnt = 0;
  while(n--)
  {
    int a;
    string s;
    cin >> a>> s;
    cout << ++cnt << " "<< s.substr(0,a-1) << s.substr(a) << endl;
  }
  return 0;
}
