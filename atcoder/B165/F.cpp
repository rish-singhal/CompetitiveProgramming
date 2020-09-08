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

vector<LL> ar(MAXN);
vector<vector<LL> > adj(MAXN);
LL BIT[MAXN];

LL max(LL a, LL b){
	return a>b?a:b;
}

int n;
int t[2*MAXN];

void modify(int p, int value) {  
  for (t[p += n+1] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) { 
  int res = 0;
  for (l += n+1, r += n+1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}

int an[MAXN];

void dfs(int u,int p){
	int old = query(ar[u], ar[u]+1);
	int	x = query(0, ar[u]); 
	int value = x + 1; 
	
	//cout<<u<<" "<<ar[u]<<" "<<x<<endl;
	modify(ar[u], max(value,old));
	an[u] = query(0,n+1);
	for(auto i:adj[u]){
		if(i!=p){
			dfs(i,u);
		}
	}
	modify(ar[u], old);
		//cout<<u<<" "<<p<<endl;
}

int main(){
  fio();
  cin>>n;
  vector<LL> v(n);
  set<LL> s;
  forn(i,n) {
  	cin>>v[i];
  	s.insert(v[i]);
  }
  int in = 0;
  map<LL,LL> mp;
  for(auto i:s){
  	mp[i] = ++in;
  }
  forn(i,n){
  	ar[i+1] = mp[v[i]];
  }
  forn(i,n-1){
  	int u, v; cin>>u>>v;
  	adj[v].pb(u);
  	adj[u].pb(v);
  }
  
  // for1(i,n) cout<<ar[i]<<" ";x
  // cout<<endl;
  
  dfs(1,0);
  for1(i,n) cout<<an[i]<<endl;

  return 0;
}
