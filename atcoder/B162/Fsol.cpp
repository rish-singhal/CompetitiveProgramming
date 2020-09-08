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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN], odds[MAXN];

int main(){
  fio();
  int n; cin>>n;
  vector<LL> v(n);
  forn(i,n) cin>>v[i];
  forn(i,n) odds[i] = ( i%2 || i<2 ?0:odds[i-2]) + v[i];
  for(int i=1;i<n;i++)
  	dp[i] = max((i>=2?dp[i-2]:0)+v[i], i%2?odds[i-1]:dp[i-1]);
  cout<<dp[n-1]<<endl;
  return 0;
}