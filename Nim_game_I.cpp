#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t_case;
    cin >> t_case;
    while (t_case--)
    {

        int n;
        cin >> n;

        int a = 0;

        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            a = a ^ b;
        }

        if (a)
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
}