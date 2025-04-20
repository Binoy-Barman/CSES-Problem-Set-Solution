#include <bits/stdc++.h>
using namespace std;
#define int long long int

int dp[1001][1001];
int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t_case ; cin>>t_case;
    // while(t_case--)  {             }

    vector<string> v;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (v[0][0] == '.')
        dp[0][0] = 1;
    else
        dp[0][0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == '.')
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
        if(v[0][i]=='*') dp[0][i]=0;
        else dp[0][i]=dp[0][i-1];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }

 

    cout << dp[n - 1][n - 1] << endl;
}