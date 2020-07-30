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
const int INF = 1e9;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<vector<int>> cap, adj;
int n;

int bfs(int s, int t, vector<int>& par){
	fill(all(par), -1);
	par[s] = -1;
	queue<pair<int,int>> q;
	q.push({s, INF});
	while(!q.empty()){
		int v, f;
		tie(v,f) = q.front();
		q.pop();
		for(auto u:adj[v]){
			if(par[u] == -1 && cap[v][u]){
				par[u] = v;
				int nflow = min(f, cap[v][u]);
				if(u==t) return nflow;
				q.push({u, nflow});
			}
		}
	}
	return 0;
}

int maxflow(int s, int t){
	int flow = 0;
	vector<int> par(n, 0);
	int nflow;
	while(nflow = bfs(s,t,par)){
		flow += nflow;
		int cur = t;
		while(cur != s){
			cap[par[cur]][cur] -= nflow;
			cap[cur][par[cur]] += nflow;
			cur = par[cur];
		}
	}
	return flow;
}


int main(){
  fio();
  
  return 0;
}