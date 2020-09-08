#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
const LL m = 1e9+7;
LL ncr[1005][1005];
LL pw[1005],pw1[1005];
LL mult(LL a, LL b)
{
  return a*b%m;
}

LL po(LL a,LL n)
{
  if(n==0) return 1;
  LL an = po(a,n/2);
  an = (an*an)%m;
  if(n&1) an = (an*a)%m;
  return an;
}

LL ss(LL n, LL a){
  if(n==0) return 0;
  if(n&1){
      return (ss(n-1,a) + pw1[a])%m;
  }
  n>>=1;
  LL an = ss(n,a);
  for(int i=0;i<=a;i++){
    an = ( an + mult(ncr[a][i],mult(pw[a-i],ss(n,i))))%m;
  }
  return an;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    for(int i=0;i<1005;i++)
    {
      ncr[i][0] = 1;
      ncr[i][i] = 1;
    }
    for(int i=1;i<1005;i++)
      for(int j=1;j<i;j++)
          ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%m;

    while(t--){
      LL n,k ;cin>>n>>k;
      pw[0]=pw1[0]=1;
      for1(i,k) 
      {
        pw[i] = (n*pw[i-1])%m;
        pw1[i] = ((n-1)*pw1[i-1])%m;
      }
      LL ann = ss(n+1,k);
      LL pp;
      if(k&1){
        pp = ((k*k)%m - 1 + m)%m;
        pp = mult(pp,po(4,m-2));
      }
      else{
        pp = (k*(k+2))%m;
        pp = mult(pp,po(4,m-2));
      }
 //     cout<<pp<<endl;
   //   pp = 0;
      cout<<((ann - pp + m)%m)<<endl;
    }
    return 0;
}

