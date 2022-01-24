#include <iostream>
#include <algorithm>
using namespace std;

int n;
int input[501][501];
int visited[501][501];
int dp[501][501];

int dfs(int i, int j)
{
    if(i<0||i>=n||j<0||j>=n) return 0;
    if(visited[i][j]) return dp[i][j];
    visited[i][j] = 1;
    int y_inc = (input[i][j] <= input[i+1][j]) ? 0 : dfs(i+1, j);
    int y_dec = (input[i][j] <= input[i-1][j]) ? 0 : dfs(i-1, j);
    int x_inc = (input[i][j] <= input[i][j+1]) ? 0 : dfs(i, j+1);
    int x_dec = (input[i][j] <= input[i][j-1]) ? 0 : dfs(i, j-1);
    dp[i][j] = max(y_inc, max(y_dec, max(x_inc, x_dec)))+1;
    return dp[i][j];
}

int main()
{
    // 입력 받기
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> input[i][j];
        }
    }
    // solve
    int maxVal = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            maxVal = max(maxVal, dfs(i, j));
        }
    }
    // 결과 출력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << maxVal << '\n';
    return 0;
}