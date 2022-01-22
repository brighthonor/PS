#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<pair<int, int>> input;
vector<int> dp;

void lis(int value, vector<int> &dp){
    int size = dp.size();
    int start = 0; int end = size;
    while(start<end){
        int mid = (start+end)/2;
        if(dp[mid]>=value) end = mid;
        if(dp[mid]<=value) start = mid+1;
    }
    if(end==size) dp.push_back(value);
    else dp[start] = value;
    return;
}

int main(){
    // 입력 받기
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        input.push_back(pair<int, int>(a, b));
    }
    // 왼쪽 전봇대 번호대로 정렬
    sort(input.begin(), input.end());
    // 오른쪽 전봇대 번호로 LIS 구하기
    for(int i=0; i<n; i++){
        lis(input[i].second, dp);
    }
    // 결과 출력
    cout << n - dp.size() << '\n';
    return 0;
}