#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mod = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N];
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
    string s;
    cin >> s;
    int n = s.size();

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    map<int, int> M;
    for (auto e : s)
        M[e]++;
    int ans = fact[n];

    for (auto e : M)
    {
        ans = (ans * modInverse(fact[e.second], mod)) % mod;
    }

    cout << ans << endl;
}