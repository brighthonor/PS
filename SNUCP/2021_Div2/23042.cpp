#include <iostream>
#include <cmath>
using namespace std;

#define MOD 1000000007

typedef long long int lli;

int n;
lli input[300001];
int sum[31];
lli ans[300001];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> input[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<30; j++)
        {
            int flag = input[i]%2;
            input[i] = input[i]/2;
            if(flag) sum[j]++;
        }
    }
    for(int i=0; i<30; i++)
        for(int j=n-1; j>=n-sum[i]; j--)
            ans[j] += pow(2, i);
    lli ret = 1;
    for(int i=0; i<n; i++)
    {
        ret = ((ret%MOD)*(ans[i]%MOD)) % MOD;
        cout << ans[i] << endl;
    }
    cout << ret << '\n';
    return 0;
}