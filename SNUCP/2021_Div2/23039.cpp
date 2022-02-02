#include <iostream>
#include <vector>
using namespace std;

int n;
int edge[11][2];

int conflict()
{
    int ret = 0;
    for(int i=0; i<n; i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        if(abs(a-b)==1 || abs(a-b)==4) continue;
        for(int j=i+1; j<n; j++)
        {
            int c = edge[j][0];
            int d = edge[j][1];
            if(abs(c-d)==1 || abs(c-d)==4) continue;
            if(a==c || a==d || b==c || b==d) continue;
            ret++;
        }
    }
    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> edge[i][0] >> edge[i][1];
    int num = conflict();
    int ret = 0;
    if(n==10) ret = -1;
    else if(num==5) ret = 2;
    else if(num>0) ret = 1;
    cout << ret << '\n';
    return 0;
}