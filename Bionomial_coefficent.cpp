#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N];
int Inversefact[N];

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
int modInverse(int a, int m)
{
    int x, y;
    int gcd = gcdExtended(a, m, x, y);
    if (gcd != 1)
        return -1;
    return (x % m + m) % m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    Inversefact[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        Inversefact[i] = (Inversefact[i - 1] * modInverse(i, mod)) % mod;
    }

    int t_case;
    cin >> t_case;
    while (t_case--)
    {

        int n, r;
        cin >> n >> r;
        int ans = (((fact[n] * Inversefact[r]) % mod) * Inversefact[n - r]) % mod;
        cout << ans << endl;
    }
}