#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][3];

int main(){
  fio();
  int n ;cin>>n;
  vector<LL> a(n), b(n),c(n);
  forn(i,n) cin>>a[i]>>b[i]>>c[i];

  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];

  for1(i,n-1){
  	dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
  	dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
  	dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);
  }
  LL an = 0;
  forn(i,3) an = max(an, dp[n-1][i]);
  cout<<an<<endl;
    return 0;
}