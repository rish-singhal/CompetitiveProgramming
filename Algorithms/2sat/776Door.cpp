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

int n,m;
vector<int> v;
vector<vector<int> > adj(MAXN);
vector<vector<int> > boo(MAXN);
vector<int> tp;
int vis[MAXN], comp[MAXN];

void dfs(int i){
	vis[i] = 1;
	for(auto j:adj[i])
		if(!vis[j]) dfs(j);
	tp.pb(i);
}

void dfs2(int i, int c){
	comp[i] = c;
	for(auto j:adj[i])
		if(!comp[j]) dfs2(j, c);
}

void check_2sat(){
	forn(i,2*m){
		if(!vis[i]) dfs(i);
	}
	int cc = 0;
	for(auto i:vector<int>(tp.rbegin(), tp.rend())){
		if(!comp[i]) dfs2(i,++cc);
	}
	for(int i=0;i<m;i++){
		if(comp[i<<1]==comp[i<<1|1]){
			cout<<"NO\n";
			exit(0);
		}
	}
	cout<<"YES\n";
}

int xx(int i){
	return 2*i;
}

int cx(int i){
	return 2*i+1;
}

int add(int a, int b){
	adj[cx(a)].pb(xx(b));
	adj[cx(b)].pb(xx(a));
	adj[xx(a)].pb(cx(b));
	adj[xx(b)].pb(cx(a));
}

int inv(int a, int b){
	adj[cx(a)].pb(cx(b));
  	adj[cx(b)].pb(cx(a));
  	adj[xx(a)].pb(xx(b));
  	adj[xx(b)].pb(xx(a));
}

int main(){
  fio();
  cin>>n>>m;
  v.resize(n);
  for(auto &i:v){
   cin>>i;
}	

  forn(i,m){	
  	int t; cin>>t;
  	while(t--){
  		int x; cin>>x;
  		x--;
  		boo[x].pb(i);
  	}
  }
  map< pair<int,int> , int> mm;
  forn(i,n){
  	int a = boo[i][0];
  	int b = boo[i][1];
  	if(v[i]==0)
  		add(a,b);
  	else 
  		inv(a,b);
  }
  check_2sat();
  return 0;
}