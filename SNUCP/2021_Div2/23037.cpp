#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    cin >> n;
    int ret = 0;
    for(int i=0; i<5; i++)
    {
        ret += pow(n%10, 5);
        n /= 10;
    }
    cout << ret << endl;
    return 0;
}