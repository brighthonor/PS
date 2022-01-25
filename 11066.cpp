#include <iostream>
using namespace std;

#define MAX 987654321

int k, n;
int input[501];
int dp[501][501];
int sum[501];

int main()
{
    // 입력 받기
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    while(k--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> input[i];
            sum[i] = input[i] + (i==0 ? 0 : sum[i-1]);
        }
        // solve by dp
        for(int diff=1; diff<n; diff++) 
        {
            for(int i=0; i<n-diff; i++)
            {
                int j = i + diff;
                int tmp = MAX;
                for(int k=i; k<j; k++)
                    tmp = min(tmp, dp[i][k]+dp[k+1][j]);
                dp[i][j] = tmp + sum[j] - sum[i] + input[i];
            }
        }
        // 결과 출력
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}