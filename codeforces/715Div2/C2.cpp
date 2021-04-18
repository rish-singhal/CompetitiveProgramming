#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin >> n;
  vector<LL> v(n);
  forn(i, n) cin >> v[i];
  vector<LL> dp(n, 0);
  sort(all(v));
  for(int len = 1; len < n; len++) {
  	for(int i = 0; i + len < n; i++){
  		dp[i] = min(dp[i], dp[i+1]) + v[i + len] - v[i];
  	}
  }
  cout << dp[0] << endl;
  return 0;
}