#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 8, dp[5] = 16, dp[6] = 32;

    if (n <= 6)
        cout << dp[n] << endl;
    else
    {

        for (int i = 7; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
            dp[i] %= mod;
        }

        cout << dp[n] << endl;
    }
}