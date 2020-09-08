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


int dp[55][55];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    for(int i=0;i<55;i++)
      for(int j=0;j<=i;j++){
          if(j==0 || j==i)
              dp[i][j] = 1;
          else
             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      }

    int t; cin>>t;
    while(t--){
      int k,n; cin>>n>>k;
      map<int,int> m;
      forn(i,n)
        {  int a; cin>>a;
           m[a]++;
        }
      LL an;
      for(auto i:m)
        {
          if(i.se<k) k-=i.se;
          else{
              an = dp[i.se][k];
              break;
          }
        }
      cout<<an<<endl;
    }
    return 0;
}

