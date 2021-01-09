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
const int MAXN = 4e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<LL> adj[MAXN];
vector<LL> vis(MAXN, 0);
LL cnt, pp;

void dfs(int i, int p){
	if(vis[i] == 0) cnt++;
	vis[i] = 1;
	set <LL> ss;
	for(auto j:adj[i]){
		ss.insert(j);
		if(j==p || j == i) continue;
		if(!vis[j]) dfs(j,i);
		else if(vis[j]) pp = 1;
		
	}
	if(ss.size() != adj[i].size())
		pp = 1;
}
 

int main(){
  fio();
  LL n; cin >> n;
  LL k;
  set <LL> s;
  forn(i,n) {
  	LL u, v; cin>> u>>v;
  	u--, v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  	k = u;
  	s.insert(u);
  	s.insert(v);
  }
  
  LL an = 0;

  for(auto z: s)
  {
  	//cout << vis[z] << endl;
  	if(vis[z] == 0){
  		pp = 0; 
  		cnt = 0;
  		// dis[z] = 1;
  		dfs(z, -1);
  		//cout << pp << " " << cnt << endl;
  		if(cnt == 1) an += cnt;
  		else an += cnt - 1 + pp;
  	}
  }
  
  cout << an << endl;
  
  return 0;
}