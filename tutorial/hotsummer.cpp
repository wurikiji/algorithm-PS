#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int t;
  cin>>t;
  while(t--)
  {
    int w;
    int a[10];
    cin >> w;
    int i = 9;
    int sum = 0;
    while(i--)
    {
      cin >> a[i];
      sum += a[i];
    }
    cout << ((sum <= w)?"YES":"NO" )<< endl;
  }
  return 0;
}
