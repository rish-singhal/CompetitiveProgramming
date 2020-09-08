#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(LL i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 5e3 +5;
const LL INF = 1e17;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,k;
vector<LL> v;
vector<vector<int>> adj(MAXN);
int sz[MAXN];
LL dp[MAXN][MAXN];

void chmin(LL &a, LL b){
	a = (a<b?a:b);
}

int btree(int l, int r){
	//cout<<l<<" "<<r<<" -- "<<endl;
	if(r<l){
		return -1;
	}
	int in = -1;
	int mi = 0;
	for(int i=l;i<=r;i++){
		if(v[i]>mi){
			mi = v[i];
			in = i;
		}
	}
	int vs[2] = {btree(l, in-1),btree(in+1,r)};
	forn(i,2) if(vs[i]!=-1) adj[in].pb(vs[i]);
	return in;
}

int dfs(int u){
	//cout<<u<<" -- "<<endl;
	sz[u] = 1;
	for(auto i:adj[u]){
		sz[u] += dfs(i);
	}
	int sk = (int)adj[u].size();
	int c1, c2;
	if(sk==0){
		dp[u][0] = 0;
		dp[u][1] = v[u];
	}
	else if(sk==1){
		c1 = adj[u][0];
		forn(s1, sz[c1]+1){
			chmin(dp[u][s1], dp[c1][s1]);
			chmin(dp[u][s1+1], dp[c1][s1] + (s1+1)*v[u]);
		}
	}
	else if(sk==2){
		tie(c1,c2) = {adj[u][0], adj[u][1]};
		forn(s1, sz[c1]+1){
			forn(s2, sz[c2]+1){
				chmin(dp[u][s1+s2], dp[c1][s1] + dp[c2][s2] + (s1*s2*v[u]));
				chmin(dp[u][s1+s2+1], dp[c1][s1]+dp[c2][s2] + (s1*s2*v[u]) + (s1+s2+1)*v[u]);
			}
		}
		forn(s1, sz[c1]+1){
			chmin(dp[u][s1], dp[c1][s1]);
			chmin(dp[u][s1+1], dp[c1][s1] + (s1+1)*v[u]);
		}
		forn(s2, sz[c2]+1){
			chmin(dp[u][s2], dp[c2][s2]);
			chmin(dp[u][s2+1], dp[c2][s2] + (s2+1)*v[u]);
		}
	}
	return sz[u];
}

void solve(){
	cin>>n>>k;
	v.assign(n,0);
	forn(i,n+1){
		sz[i]= 0;
		adj[i].clear();
		forn(j,n+1){
			dp[i][j] = INF;
		}
	}
	forn(i,n) cin>>v[i];
	int root = btree(0, n-1);
	//cout<<root<<endl;
	dfs(root);
	LL an = INF;
	for(int i = k; i<=n; i++){
		chmin(an, dp[root][i]);
	}
	cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}