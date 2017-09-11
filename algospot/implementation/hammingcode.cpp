/* hamming(7, 4 ) encodes 4 bits to 7-bit code

   */

#include <iostream>
#include <string>

using namespace std;


int stoi(char c)
{
  return c-'0';
}
int main(void)

{
  int t;
  cin>>t;
  while(t--)
  {
    string s; 
    cin >> s;
    int first = (stoi(s[0]) ^ stoi(s[2]) ^ stoi(s[4]) ^ stoi(s[6]));
    int second = (stoi(s[1]) ^ stoi(s[2]) ^ stoi(s[5]) ^ stoi(s[6]));
    int third = (stoi(s[3]) ^ stoi(s[4]) ^ stoi(s[5]) ^ stoi(s[6]));

    int error = 4 * third + 2 * second + first;

    if( error ) 
      s[error-1] = ((stoi(s[error-1]) + 1 )%2) + '0';

    cout<< s[2]<<s[4]<<s[5]<<s[6]<<endl;
  }
  return 0;
}
