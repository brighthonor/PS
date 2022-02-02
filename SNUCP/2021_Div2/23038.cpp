#include <iostream>
using namespace std;

int n, m;
char input[903][903];
char ans[903][903];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<3*n; i++)
        for(int j=0; j<3*m; j++)
            cin >> input[i][j];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if((i+j)%2)
            {
                for(int a=0; a<3; a++)
                    for(int b=0; b<3; b++)
                        ans[3*i+a][3*j+b] = '.';
                ans[3*i+1][3*j+1] = '#';
                // 상, 하, 좌, 우 순서 확인
                if(i!=0 && input[3*i-1][3*j+1]=='#')
                    ans[3*i][3*j+1] = '#';
                if(i!=n-1 && input[3*i+3][3*j+1]=='#')
                    ans[3*i+2][3*j+1] = '#';
                if(j!=0 && input[3*i+1][3*j-1]=='#')
                    ans[3*i+1][3*j] = '#';
                if(j!=m-1 && input[3*i+1][3*j+3]=='#')
                    ans[3*i+1][3*j+2] = '#';
            }
            else
            {
                for(int a=0; a<3; a++)
                    for(int b=0; b<3; b++)
                        ans[3*i+a][3*j+b] = input[3*i+a][3*j+b];
            }
        }
    }
    for(int i=0; i<3*n; i++)
    {
        for(int j=0; j<3*m; j++)
            cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}