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

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int powermod(int n, int p)
{
    if (p == 0)
        return 1;
    int temp = n % mod;
    int mul = 1;
    for (int i = 0; p > 0; i++)
    {

        if (p & 1)
        {
            mul = (mul * temp) % mod;
        }
        p = p >> 1;
        temp = (temp * temp) % mod;
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


    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum= (sum+powermod(m,gcd(n,i)))%mod;
        //cout<<sum<<" "<<gcd(n,i)<<endl;


    }

    sum= (sum*modInverse(n,mod))%mod;
    cout<<sum<<endl;
}