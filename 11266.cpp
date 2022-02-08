#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<int> vc[10001];
int discover[10001];
bool cutpoint[10001];
int cnt = 0;

int dfs(int node, bool isRoot)
{
    discover[node] = cnt++;
    int ret = discover[node];
    int children = 0;
    for(auto next : vc[node])
    {
        if(discover[next]==-1)
        {
            children++;
            int subtree = dfs(next, false);
            if(!isRoot && subtree>=discover[node]) cutpoint[node] = true;
            ret = min(ret, subtree);
        }
        else ret = min(ret, discover[next]);
    }
    if(isRoot) cutpoint[node] = (children>=2);
    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e;
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a >> b;
        vc[a-1].push_back(b-1);
        vc[b-1].push_back(a-1);
    }
    for(int i=0; i<v; i++)
    {
        discover[i] = -1;
        cutpoint[i] = false;
    }
    for(int i=0; i<v; i++)
        if(discover[i]==-1) dfs(i, true);
    queue<int> q;
    for(int i=0; i<v; i++)
        if(cutpoint[i]) q.push(i+1);
    cout << q.size() << '\n';
    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
    return 0;
}