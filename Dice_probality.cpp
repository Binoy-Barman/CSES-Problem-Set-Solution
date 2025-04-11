
#include <bits/stdc++.h>
using namespace std;
#define int long long int


vector<vector<int>> Mat_Mul(vector<vector<int>> &v1, vector<vector<int>> &v2)
{
    // The resulting matrix should have dimensions v1.size() x v2[0].size()
    vector<vector<int>> ans(v1.size(), vector<int>(v2[0].size()));

    for (int i = 0; i < v1.size(); i++)
    { // Loop over rows of v1
        for (int j = 0; j < v2[0].size(); j++)
        { // Loop over columns of v2
            ans[i][j] = 0;
            for (int k = 0; k < v1[0].size(); k++)
            { // Loop over columns of v1/rows of v2
                ans[i][j] = ans[i][j] + ((v1[i][k] * v2[k][j])) ;
            }
        }
    }

    return ans;
}


int dice_counting(int n)
{
    vector<vector<int>> v = {
        {32},
        {16},
        {8},
        {4},
        {2},
        {1}};

    vector<vector<int>> fact = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };
    vector<vector<int>> mul = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
    };
   if(n<=0)
   {
     return 0;
   }
  
    if (n <= 6)
    {
       return v[6 - n][0];
        
    }

    int temp = n - 6;

    while (temp > 0)
    {
        // cout << temp << endl;
        if (temp & 1)
        {
            mul = Mat_Mul(mul, fact);
            // cout << "a" << endl;
        }

        temp = temp >> 1;
        fact = Mat_Mul(fact, fact);
    }

    vector<vector<int>> ans = Mat_Mul(mul, v);

    return ans[0][0] ;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t_case ; cin>>t_case;
    // while(t_case--)  {             }
int n;
int a;
int b;
cin>>a>>b>>n;
double ans= (double(dice_counting(b)-dice_counting(a-1)))/( double(dice_counting(n)));
cout<<ans<<endl;

   
}