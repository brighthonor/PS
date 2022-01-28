#include <iostream>
#include <stack>
using namespace std;

// pair< index, value >
typedef pair<int, long long int> pi;

int n;
long long int input[100001];
long long int rsn[100001], lsn[100001];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    while(true)
    {
        // 입력받기
        cin >> n;
        if(n==0) break;
        for(int i=0; i<n; i++)
            cin >> input[i];
        // 오작수 구하기
        stack<pi> s1;
        for(int i=n-1; i>=0; i--)
        {
            while(!s1.empty()&&input[i]<=s1.top().second)
                s1.pop();
            if(!s1.empty()) rsn[i] = s1.top().first;
            else rsn[i] = n;
            s1.push(make_pair(i, input[i]));
        }
        // 왼작수 구하기
        stack<pi> s2;
        for(int i=0; i<n; i++)
        {
            while(!s2.empty()&&input[i]<=s2.top().second)
                s2.pop();
            if(!s2.empty()) lsn[i] = s2.top().first;
            else lsn[i] = -1;
            s2.push(make_pair(i, input[i]));
        }
        // 오작수, 왼작수 이용해서 답 구하기
        long long int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans, input[i]*(rsn[i]-lsn[i]-1));
        }
        // 결과 출력
        cout << ans << '\n';
    }
    return 0;
}