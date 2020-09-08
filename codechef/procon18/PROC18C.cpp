using namespace std;
#include <bits/stdc++.h>
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
const LL m = 1e9+ 7;
LL dp[200][20][2][2];
string a,b;

int solve(int sum, int ind, int uf, int lf){  
  if(sum<0) return 0;
  if(ind >= a.size()) return sum==0;
  if(dp[sum][ind][uf][lf]!=-1) return dp[sum][ind][uf][lf];
  int ll = a[ind]-'0', uu = b[ind]-'0';
  LL &ans = dp[sum][ind][uf][lf];
  ans = 0;
  for(int d=0;d<=9;d++)
    if( (uf || d<=uu) && (lf || d>=ll))
     ans =(ans + solve(sum-d,ind+1,uf|(d<uu),lf|(d>ll)))%m;
  return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      memset(dp,-1,sizeof dp); 
      cin>>a>>b;
      string t = "";
      forn(i,b.size()-a.size())
        t+="0";
      t+=a;
      a = t;
      vector<LL> cnt(200);
      LL an = 0;
      
      for(int i=1;i<=170;i++)
        cnt[i] = solve(i,0,0,0);
      
      for(int i=1;i<=170;i++)
        for(int j=1;j<i;j++)       
          if(gcd(i,j)==1)
            an = ( an + cnt[i]*cnt[j])%m;
      an = ( an + (cnt[1]*(cnt[1]-1)/2))%m;
      cout<<an<<endl;
    
      }
    return 0;
}

