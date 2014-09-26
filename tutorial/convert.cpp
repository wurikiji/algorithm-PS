#include <cstring>
#include <string>
#include <iostream>
#include <map>
using namespace std;



int main(void){
  int n;
  cin>>n;
  int cnt=0;
  map<string,string> m;

  m[string("kg")]=string("lb");
  m[string("lb")]=string("kg");
  m[string("l")]=string("g");
  m[string("g")]=string("l");
  
  map<string,double> mm;
  mm[string("kg")]=(double)2.2046;
  mm[string("lb")]=(double)0.4536;
  mm[string("l")]=(double)0.2642;
  mm[string("g")]=(double)3.7854;
  while(n--)
  {
    double a;
    string s;
    cin>>a>>s;
    cout<<fixed;
    cout.precision(4);
    cout<<++cnt<<" "<< a * mm[s] <<" "<<m[s]<<endl;
  }
  return 0;
}
