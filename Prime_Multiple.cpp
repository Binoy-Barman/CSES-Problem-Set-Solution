#include<bits/stdc++.h>
using namespace std;
#define int long long int




int32_t main()
{
    ios_base::sync_with_stdio(false);     
    cin.tie(NULL); cout.tie(NULL); 

   

   int  n,k; cin>>n>>k;
   vector<int>v(k);
   for(int i=0;i<k;i++)
   {
     cin>>v[i];
   }

   int ans=0;

   for(int i=1;i<(1LL<<k);i++)
   {
         int ct=0;
         int gcd=1;
      for(int j=0;j<k;j++)
      {
        if((i & (1LL<<j))){

          if(gcd>n/v[j]) {
            gcd=n+1; 
            break;
          }

          gcd*=v[j];
          ct++;
        }
      
      }

      int  times= n/gcd;

      if(ct%2==0) {
         ans-=times;
      }
      else{
        ans+=times;
      }
   }

   cout<<ans<<endl;




}