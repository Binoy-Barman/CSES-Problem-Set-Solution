#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

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
        mul = (((mul * ((n - i + 1) % mod)) % mod) * modInverse(i, mod)) % mod;
    }
    return mul;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t_case ; cin>>t_case;
    // while(t_case--)  {             }

    int n;
    string s;
    cin >> n >> s;
    int close = 0;
    int open = 0;
    for (auto e : s)
    {
        if (e == ')')
            close++;
        else
            open++;
        if (close > open)
        {
            cout << "0" << endl;
            return 0;
        }
    }

    if (n % 2 == 1 || n < 2 * open)
    {
        cout << '0' << endl;
        return 0;
    }

    int k = open-close; // opening braket prefix
      n= n/2-open; // remaing pair

    int catalon = (((nCr(2 * n + k, n)) * (k + 1) % mod) * modInverse(n + k + 1, mod)) % mod;
    cout << catalon << endl;
}