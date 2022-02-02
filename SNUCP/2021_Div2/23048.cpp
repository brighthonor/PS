#include <iostream>
#include <cmath>
using namespace std;

int n;
int color[500001];

int isPrime(int num)
{
    int loop = sqrt(num);
    for(int i=2; i<=loop; i++)
    {
        if(!(num%i)) return i;
    }
    return -1;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int c = 1;
    for(int i=1; i<=n; i++)
    {
        int div = isPrime(i);
        if(div==-1) color[i] = c++;
        else color[i] = color[div];
    }
    cout << c-1 << '\n';
    for(int i=1; i<=n; i++)
        cout << color[i] << ' ';
    cout << '\n';
    return 0;
}