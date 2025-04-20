#include <bits/stdc++.h>
using namespace std;
#define int long long int

int const N = 2e6 + 10;
int dp[N];
const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t_case ; cin>>t_case;
    // while(t_case--)  {             }

    int n, k;
    cin >> n >> k;

    set<int> s;
    for (int i = 0; i <= k; i++)
        dp[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    dp[0] = 1;

    for (auto e : s)
    {
        for (int i = e; i <= k; i++)
        {
            dp[i] += dp[i - e];
            dp[i] %= mod;
        }

        // cout<<e<<endl;
    }

    cout << dp[k] << endl;
}