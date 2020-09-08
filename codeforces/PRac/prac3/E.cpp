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

vector <vector<int>> adj(MAXN);
int dis[MAXN];
vector <int> tp;
int inx[MAXN];
int out[MAXN];

void dfs(int u, int p){
	dis[u] = (dis[p]+1)%2;
	tp.pb(u);
	inx[u] = tp.size();
	for(auto i:adj[u]){
		if(i!=p) dfs(i,u);
	}
	out[u] = tp.size();
}

LL bit[2][MAXN];

void up(LL x, LL v, int in){
	while(x<MAXN){
		bit[in][x]+=v;
		x+=x&-x;
	}
}

LL qu(LL x, int in){
	LL an = 0;
	while(x>0){
		an+=bit[in][x];
		x-=x&-x;
	}
	return an;
}

vector<LL> an(MAXN);

int main(){
  fio();
  int n,m; cin>>n>>m;
  for1(i,n){
  	cin>>an[i];
  }
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }

  dfs(1,0);
  // for(auto i:tp) cout<<i<<" ";
  // cout<<endl;
  // for1(i,n){
  // 	cout<<i<<": "<<inx[i]<<" "<<out[i]<<" "<<dis[i]<<endl;
  // }
  while(m--){
  	int in; cin>>in;
  	if(in==1){
  		LL x, v; cin>>x>>v;
  		up(inx[x], v, dis[x]);
  		up(out[x]+1, -v, dis[x]);
  		up(inx[x], -v, dis[x]^1);
  		up(out[x]+1, +v, dis[x]^1);
  	}
  	else{
  		int x; cin>>x;
  		cout<<(qu(inx[x],dis[x]) + an[x])<<endl;
  	}
  }
  return 0;
}