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

struct Dinic{
	struct Edge{
		int to, rev;
		LL c, fc;
		LL flow(){ return max(fc - c, 0LL); }
	};
	bool SCALING;
	vi lvl, q, ptr;
	vector<vector<Edge>> adj;
	Dinic(int n, bool ch = 0): lvl(n), q(n), ptr(n), adj(n), SCALING(ch){}
	void addEdge(int a, int b, LL cap, LL rcap = 0){
		adj[a].pb({b, sz(adj[b]), cap, cap});
		adj[b].pb({a, sz(adj[a])-1, rcap, rcap});
	}
	LL dfs(int v, int t, LL f = LLONG_MAX){
		if(v==t || !f) return f;
		for(int &i = ptr[v]; i < sz(adj[v]); i++){
			auto& e = adj[v][i];
			if(lvl[e.to] == lvl[v] + 1)
				if(LL p = dfs(e.to, t, min(f, e.c))){
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	LL calc(int s, int t){
		LL flow = 0; q[0] = s;
		for(LL lim = SCALING? (1<<30):1; lim > 0; lim >>= 1) do{
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while(qi < qe && !lvl[t]){
				int v = q[qi++];
				for(auto e : adj[v])
					if(!lvl[e.to] && e.c > 0 && (!SCALING || e.c >= lim))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
				}
			while(LL p = dfs(s, t)) flow += p;
		} while(lvl[t]);
		return flow;
	}
	bool lsmin(int a){ return lvl[a]!=0; }
};


int main(){
  fio();
  int n,m,p; cin>>n>>m>>p;
  Dinic d(n+m+2);
  forn(i,p){
  	int a,b; cin>>a>>b;	
  	d.addEdge(a, n+b, 1);
  }
  for1(i,n){
  	d.addEdge(0, i, 1);
  }
  for1(i,m){
  	d.addEdge(n+i, n+m+1, 1);
  }
  cout<<d.calc(0, n+m+1)<<endl;
  return 0;
}