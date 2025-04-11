#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e6 + 200;
bool arr[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> move(k);
    for (int i = 0; i < k; i++)
    {
        cin >> move[i];
    }

    for (int i = 0; i <= n; i++)
    {

        if (!arr[i])
        {
            for (auto e : move)
            {
                arr[i + e] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {

        if (arr[i])
            cout << 'W';
        else
            cout << 'L';
    }
}