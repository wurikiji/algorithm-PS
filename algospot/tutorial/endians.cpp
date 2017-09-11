#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  int n;
  scanf("%d", &n);
  while(n--)
  {
    unsigned int a;
    cin>>a;
    cout<< ((a<<24) | ((a<< 8)&0x00ff0000) | ((a>>8)&0x0000FF00) | ((a>>24)&0x000000ff))<<endl;
  }
  return 0;
}
