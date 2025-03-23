#include<bits/stdc++.h>
using namespace std;
#define int long long int


int m=1e9+7;
vector<int>Multi(vector<int>a,vector<int>b)
{
    int a11=((a[0]*b[0])%m+(a[1]*b[2])%m)%m;
    int a12=((a[0]*b[1])%m+(a[1]*b[3])%m)%m;
    int a21=((a[2]*b[0])%m+(a[3]*b[2])%m)%m;
    int a22=((a[2]*b[1])%m+(a[3]*b[3])%m)%m;

    return {a11,a12,a21,a22};
  
}

int32_t main()
{
    ios_base::sync_with_stdio(false);     
    cin.tie(NULL); cout.tie(NULL); 

    vector<int>v[64];
    v[0]={1,1,1,0};

for(int i=1;i<=62;i++)
{
    v[i]=Multi(v[i-1],v[i-1]);
}



int n; cin>>n;
if(n==0){cout<<'0'<<endl; return 0;}
vector<int>current={1,0,0,1};

int temp=n-1;

for(int i=0;i<10;i++)
{
    if((temp & (1<<i))!=0){

        current=Multi(current,v[i]);
    
    }
}

cout<<current[0]<<endl;



}