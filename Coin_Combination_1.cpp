#include <bits/stdc++.h>
using namespace std;
#define int long long int
int const mod=1e9+7;

int const N = 2e6 + 10;
int arr[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t_case ; cin>>t_case;
    // while(t_case--)  {             }

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (auto e : v)
    {
        arr[e] = 1;
    }

    for (int i = 0; i <= k; i++)
    {
        if (arr[i] != 0)
        {
            for (auto e : v)
            {
                arr[i + e] = arr[i + e] + arr[i];
                arr[i+e]%=mod;
            }
        }
    }

    cout << arr[k] << endl;
}