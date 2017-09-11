#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

  int t;
  cin>>t;
  while(t--)
  {
    string s;
    vector<string> v;
    cin>>s;
    for(int i = 0 ;i < (s.length()+1)/2;i++)
    {
      v.push_back(s.substr(i*2,2));
    }
    sort(v.begin(),v.end());

    for(int i = 0; i < v.size();i++)
      cout << v[i];

    cout<<endl;
  }
  return 0;
}
