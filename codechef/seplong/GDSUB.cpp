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
const LL m = 1e9 + 7; 
LL dp[2010][2010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;  
    int k,n; cin>>n>>k;
    map <int,int> mm;
    forn(i,n){
      int a; cin>>a;
      mm[a]++;
    }
    vector <LL> v;
    for(auto i:mm) v.pb(i.se);
    int w = v.size();
    forn(i,w+1){
        forn(j,i+1){
          if(j==0) dp[i][j] = 1;
          else if(i==0) continue;
          else
          {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*v[i-1])%m;
          }
       }
    }
/*   for(int i=0;i<=w;i++)
    {
       for(int j=0;j<=w;j++)
          cout<<dp[i][j]<<" ";
        cout<<endl;
    }
  */  
    LL an = 0;
    for(int i=0;i<=k;i++)
      an = (an + dp[w][i])%m;
    cout<<an<<endl;
    return 0;
}

