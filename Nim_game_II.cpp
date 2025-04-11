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
        int w = 0, l = 0;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a % 4 == 0)
                l++;
            else
                w++;
        }

        int d = abs(w - l);

        if (w >= l)
        {

            if (d % 2 == 1)
                cout << "first" << endl;
            else
                cout << "second" << endl;
        }
        else
        {

            if (d % 2 == 1)
                cout << "second" << endl;
            else
                cout << "first" << endl;
        }
    }
}