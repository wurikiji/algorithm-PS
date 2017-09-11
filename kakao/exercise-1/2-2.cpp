#include<vector>
#include <cstring>
using namespace std;

int chk[100100];

bool solution(vector<int> arr)
{
	bool answer = true;
    memset(chk,0,sizeof(chk));
    for(int i = 0;i < arr.size();i++) {
        if (chk[arr[i]] != 0)
            return false;
        if (arr[i] > arr.size())
            return false;
        chk[arr[i]] = 1;
    }
	return answer;
}
