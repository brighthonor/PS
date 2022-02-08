#include <iostream>
#include <vector>
using namespace std;

#define SZ 20003

int n, m;
vector<int> vc[SZ];
int disc[SZ];
int depth[SZ];
int count = 1;
long long int ans = 1;

void dfs(int s, int e)
{
    disc[s] = count++;
    depth[s] = depth[e]+1;
    bool isOne = true;
    for(auto next : vc[s])
    {
        if(next==e) continue;
        if(disc[next]!=0)
        {
            if(!isOne){
                ans = 0;
                cout << s << endl;
            }
            if(depth[s]-depth[next]>0)
            {
                ans *= depth[s] - depth[next] + 2;
                isOne = false;
            }
        }
        else dfs(next, s);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int num;
        cin >> num;
        int fn, sn;
        cin >> fn;
        for(int j=0; j<num-1; j++)
        {
            cin >> sn;
            vc[fn].push_back(sn);
            vc[sn].push_back(fn);
            fn = sn;
        }
    }
    bool isOne = true;
    for(int i=1; i<=n; i++)
    {
        if(disc[i]==0)
        {
            if(!isOne) ans = 0;
            dfs(i, 0);
            isOne = false;
        }
    }
    cout << ans << '\n';
    return 0;
}