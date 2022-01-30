#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long int input[500001];
int digit[11];

void count(int i)
{
    while(i)
    {
        digit[i%10]++;
        i = i/10;
    }
    return;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력 받기
    cin >> m >> n;
    // solve (brute force)
    for(int i=m; i<=n; i++)
        count(i);
    // 결과 출력
    int ret = 0;
    for(int i=0; i<10; i++)
        cout << digit[i] << " ";
    cout << '\n';
    return 0;
}