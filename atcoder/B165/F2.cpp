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


vector<vector<int>> adj(MAXN);

LL max(LL a, LL b){
	return a>b?a:b;
}

int n;
vector<LL> v;
int an[MAXN];
vector <int> lc;

void dfs(int u,int p){
	auto x = lower_bound(all(lc), v[u]) - lc.begin();
	int	ch = x;
	int val = lc[x];
	lc[x] = v[u];
	an[u] = lower_bound(all(lc), INT_MAX) - lc.begin();
	for(auto i:adj[u]){
		if(i!=p){
			dfs(i,u);
		}
	}
	lc[x] = val;
}

int main(){
  fio();
  cin>>n;
  set<LL> s;
  forn(i,n) {
  	int x; cin>>x;
  	v.pb(x);
  }
  lc.resize(n+1);
  forn(i,n+1) lc[i] = INT_MAX;
  forn(i,n-1){
  	int u, x; cin>>u>>x;
  	u--, x--;
  	adj[x].pb(u);
  	adj[u].pb(x);
  } 
  dfs(0,-1);
  forn(i,n) cout<<an[i]<<endl;

  return 0;
}
