#include <iostream>
#include <vector>
using namespace std;

int c, b;
int input[22];
vector<int> vc;

int search(int i, int sum)
{
    if(i==b) return sum;
    if(sum+input[i] > c) 
        return search(i+1, sum);
    else
    {
        int a = search(i+1, sum);
        vc.push_back(input[i]);
        int b = search(i+1, sum+input[i]);
        return max(a, b);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력 받기
    cin >> c >> b;
    for(int i=0; i<b; i++)
        cin >> input[i];
    // solve (brute force)
    int ans = search(0, 0);
    // 결과 출력
    cout << ans << '\n';
    return 0;
}