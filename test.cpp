#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e6 + 10;
int dp[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;  // base case: 1 way to make sum 0

    for (auto coin : coins) {
        for (int i = coin; i <= k; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[k] << endl;
}
