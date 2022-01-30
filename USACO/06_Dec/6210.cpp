#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

int d;
lli n;

bool isPrime(lli num)
{
    lli sq = sqrt(num/1.0);
    for(lli i=2; i<=sq; i++)
        if(num%i==0) return false;
    return true;
}

bool isWonderPrime(lli num)
{
    for(int i=d; ; i++)
    {
        lli mod = pow(10, i);
        lli a = num / mod;
        lli b = num % mod;
        if(a*10<pow(10,d)) break;
        if(b*10<mod) continue;
        if(isPrime(a) && isPrime(b)) return true;
    }
    return false;
}

int main()
{
    // 입력 받기
    cin >> d >> n;
    // solve
    lli ans = -1;
    if(n<(pow(10, 2*d-1)+pow(10, d-1))) n = pow(10, 2*d-1)+pow(10, d-1);
    for(lli i=n; ; i++){
        if(isWonderPrime(i))
        {
            ans = i;
            break;
        }
    }
    // 결과 출력
    cout << ans << '\n';
    return 0;
}
