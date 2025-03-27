#include <bits/stdc++.h>
using namespace std;
#define int long long int


int mod = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N];
int comb[N];

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

int nCr(int n,int r)
{
    if(r>n-r) r=n-r;
    
    int mul=1;
    for(int i=1;i<=r;i++)
    {
        mul*=(n-i+1);
        mul/=i;
    }
    return mul;
}



int32_t main()
{
    int n;
    cin >> n;
    fact[0] = 1;
    comb[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        comb[i] =(( comb[i-1]*(n-i+1))%mod * modInverse(i,mod))%mod;
    }

    int sum=0;

    for(int i=0;i<=n;i++)
    {
        if(i&1){
            sum -=  (comb[i]*fact[n-i])%mod;
        }
        else{
            sum +=  (comb[i]*fact[n-i])%mod;
        }
   
        if(sum>=mod) sum-=mod;
        if(sum<0) sum+=mod;
    }
 

    cout<<sum<<endl;
}