#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mod = 1e9 + 7;

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

int nCr(int n, int r)
{
    if (r > n - r)
        r = n - r;

    int mul = 1;
    for (int i = 1; i <= r; i++)
    {
        mul = (mul*(n - i + 1))%mod;
    
        mul = (mul*modInverse(i,mod))%mod;
    }
    return mul;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    cout << nCr(n + m - 1, n - 1) << endl;
}