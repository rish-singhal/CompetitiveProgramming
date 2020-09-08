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

LL n;
vector<vector<int> > adj(MAXN);
vector<int> cc(MAXN);
LL sz[MAXN];
LL ann[MAXN];
LL zx[MAXN];

LL dfs(int u, int p){
	sz[u] = 1;
	vector<LL> vv;
	for(auto i:adj[u]){

		if(i!=p){
			LL k  = dfs(i,u);
			vv.pb(k);
			sz[u]+= k;
		}
	}
	vv.pb(n-sz[u]);
	LL ak = 0 ;
	LL zz = 0;
	for(auto i:vv) ak+=i;
	for(auto i:vv) zz+=(i*(ak-i));
	ann[cc[u]]+=(zz/2)+ak+1;
  cout<<cc[u]<<" "<<(zz/2)<<" "<<ak<<" "<<ann[cc[u]]<<endl;
	return sz[u];
}



int main(){
  fio();
  cin>>n;

  forn(i,n) {
  	cin>>cc[i];
  	zx[cc[i]]++;
  }
  forn(i,n-1){
  	int u, v; cin>>u>>v;
  	u--, v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dfs(0,-1);
  // LL am = 0;
  // for1(i,n){
  // 	am += (zx[i]*(zx[i]-1)/2);
  // }
  for1(i,n){
  	ann[i]-=(zx[i]*(zx[i]-1))/2;
  }
  for1(i,n) cout<<ann[i]<<endl;
  return 0;
}