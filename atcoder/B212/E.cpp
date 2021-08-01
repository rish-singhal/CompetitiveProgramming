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
const int MAXN = 5e3 +5;
const LL mm = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int>> adj(MAXN);

int main(){
  fio();
  int n, m, k; cin >> n >> m >> k;
  forn (i, m) {
  	int u, v; cin >> u >> v;
  	u--, v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  vector <LL> dp(n, 0);
  dp[0] = 1;
  LL su = 1;
  forn (i, k) {
  	vector <LL> ndp(n, 0);
  	LL nsu = 0;
  	forn(v, n) {
  		ndp[v] = su;
  		for(auto c: adj[v]) {
  			ndp[v] = (ndp[v] - dp[c] + mm) % mm;
  		}
  		ndp[v] = (ndp[v] - dp[v] + mm) % mm;
  		nsu = (nsu + ndp[v]) % mm;
  	}
  	su = nsu;
  	dp = ndp;
  }
  cout << dp[0] << endl;
  return 0;
}