#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int n, a, b;
vector<int> vc[100001];
char color[100001];
int visited[100001];
long long int memo[100001];
stack<int> s;

long long int dfs(int root, int node)
{
    if(memo[node]!=0 && color[node]=='R') return memo[node];
    if(color[node]=='R') s.push(node);
    visited[node] = root+1;
    long long int ret =0;
    for(int i=0; i<vc[node].size(); i++)
    {
        if(visited[vc[node][i]]==root+1) continue;
        if(color[vc[node][i]]=='B') continue;
        long long int cnt = dfs(root, vc[node][i]);
        ret += cnt + 1;
        if(color[node]=='B')
            while(!s.empty())
            {
                memo[s.top()] = cnt;
                s.pop();
            }
    } 
    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        cin >> a >> b;
        vc[a-1].push_back(b-1);
        vc[b-1].push_back(a-1);
    }
    for(int i=0; i<n; i++)
        cin >> color[i];
    // Solve (DFS)
    long long int ret = 0;
    for(int i=0; i<n; i++)
    {
        if(color[i]=='R') continue;
        ret += dfs(i, i);
    }
    cout << ret << '\n';
    return 0;
}