#include <bits/stdc++.h>
using namespace std;
#define int long long int

int v[200];
int n;
const int N = 1e6 + 7;
int dp[N][101];

int fun(int index, int r)
{
   if(dp[r][index]!=0) return dp[r][index];
    if (r == 0)
        return 0;
    if (index >= n || r < 0)
        return N;

    int h = N;

    for (int i = 0; i <= r / v[index]; i++)
    {
        dp[r-v[index]*i][index] = fun(index + 1, r - v[index] * i)+i;
        h=min(h,dp[r-v[index]*i][index]);
    }

    dp[r][index]=h;
    return dp[r][index];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> n >> k;
  
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = fun(0, k);


   if(ans!=N) cout << ans << endl;
   else cout<<"-1"<<endl;
}