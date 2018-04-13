#include<vector>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int dp[1010][1010][3];

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int x = board.size();
    int y = board[0].size();
    memset(dp,0,sizeof(dp));
	// 현재 내 위치까지 오는동안 정사각형을 만들 수 있는
	// 가장 긴 가로,세로,대각선 길이를 다음 가로,세로,대각선에 저장
    for (int i = 0 ;i < board.size();i++) {
        for (int j= 0 ;j < board[i].size();j++) {
            if (board[i][j]) {
				// 1 로 표기가 되어있는 경우
                int minx = 1010;
                for (int k = 0 ;k < 3;k++) {
                    dp[i][j][k]++; // 현재 위치도 길이에 포함되어야 하므로 1 증가
					// 정사각형을 가득 채울 수 있으려면, 가로/세로/대각선이 모두 
					// 가득 차 있어야 한다.
					// 셋 중 가장 작은 길이만큼이 가득 채울 수 있는 공간
                    minx = min(minx, dp[i][j][k]); 
                }
                for (int k = 0 ;k < 3; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < x && ny < y && board[nx][ny]) 
                        dp[nx][ny][k] += minx;
                }
            }
        }
    }
    for (int i = 0 ;i < board.size();i++) {
        for (int j= 0 ;j < board[i].size();j++) {
            if (board[i][j]) {
                int minx = 1010;
                for (int k = 0 ;k < 3;k++) {
                    minx = min(minx, dp[i][j][k]);
                }
                answer = max(answer, minx);
            }
        }
    }
    return answer * answer;
}
