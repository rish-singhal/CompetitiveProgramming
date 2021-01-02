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
const int MAXN = 2e5 +5;
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int>> adj(MAXN);
LL dis[MAXN];
LL val[MAXN];

void dfs(int u, int p){
	if(p == -1)
		dis[u] = 0;
	else 
		dis[u] = dis[p] + 1;

	for(auto v: adj[u])
		if(v != p)
			dfs(v, u);
}

void dfs2(int u, int p){
	if(p != -1)
		val[u] += val[p];

	for(auto v: adj[u])
		if(v != p)
			dfs2(v, u);
}

int main(){
  fio();	
  int n; cin >> n;
  vector <pair <LL, LL>> e(n);
  forn(i,n - 1){
  	cin >> e[i].fi >> e[i].se;
  	e[i].fi--, e[i].se--;
  	adj[e[i].fi].pb(e[i].se);
	adj[e[i].se].pb(e[i].fi);
  }
  int q; cin >> q;
  LL su = 0;
  dfs(0, -1);
  while(q--)
  {
  	int t; cin>>t;
  	LL i, x; cin>>i >> x;
  	i--;
  	if(t == 1){
  		if(dis[e[i].fi] < dis[e[i].se])
  			{
  				val[e[i].se] -= x;
  				su += x;
  			}
  		else
  			val[e[i].fi] += x;
  	}
  	else{
  		if(dis[e[i].fi] < dis[e[i].se])
  			{
  				val[e[i].se] += x;

  			}
  		else
  			{
  				val[e[i].fi] -= x;
  		  		su += x;
  		  	}
  	}
  }

  dfs2(0, -1);
  forn(i, n)
  	cout << val[i] + su <<endl;

  return 0;
}
