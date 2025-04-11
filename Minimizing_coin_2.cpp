#include <bits/stdc++.h>
using namespace std;
#define int long long int

int const N = 2 * (1e6 + 100);
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

    sort(v.begin(), v.end());

    reverse(v.begin(), v.end());

    for (auto e : v)
    {
        arr[e] = 1;

        for (int i = e + 1; i <= k; i++)
        {
            if (arr[i - e] != 0)
            {
                if (arr[i] == 0)
                    arr[i] = arr[i - e] + 1;
                else
                    arr[i] = min(arr[i], arr[i - e] + 1);
            }
        }

    }

    if (arr[k] == 0)
        cout << "-1" << endl;
    else cout<<arr[k]<<endl;
}