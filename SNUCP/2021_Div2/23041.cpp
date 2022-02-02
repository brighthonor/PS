#include <iostream>

using namespace std;

typedef long long int lli;

lli n, m;

lli gcd(lli a, lli b)
{
    lli tmp;
    if(a<b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b!=0)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    lli ret = gcd(n+m, abs(n-m));
    bool flag = false;
    if(!(ret%2))
        if( (ret/2)%gcd(n, m) == 0 )
            flag = true;
    ret *= ret;
    if(flag) ret /= 2;
    cout << ret << endl;
    return 0;
}