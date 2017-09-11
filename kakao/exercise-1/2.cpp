#include<vector>
#include <algorithm>
using namespace std;

bool solution(vector<int> arr)
{
	bool answer = true;
    sort(arr.begin(), arr.end());
    for (int i = 0 ;i < arr.size() - 1;i++)
        if (arr[i] == arr[i+1]) {
            answer = false;
        }
    
    if (arr[arr.size()-1] > arr.size())
        answer = false;
	return answer;
}
