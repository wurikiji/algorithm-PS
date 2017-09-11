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
    for (int i = 0 ;i < board.size();i++) {
        for (int j= 0 ;j < board[i].size();j++) {
            if (board[i][j]) {
                int minx = 1010;
                for (int k = 0 ;k < 3;k++) {
                    dp[i][j][k]++;
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
