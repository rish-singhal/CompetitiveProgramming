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
const int MAXN = 5e4 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int par[MAXN];
vector <vector<int>> adj(MAXN);
void dfs(int u, int p){
	//cout<<u<<endl;
	par[u] = p;
	for(auto i:adj[u]){
		if(i!=p) dfs(i,u);
	}
}

int main(){
  fio();
  int n,r1,r2;
  cin>>n>>r1>>r2;
  for1(i,n){
  	if(i==r1) continue;
  	int x; cin>>x;
  	adj[x].pb(i);
  	adj[i].pb(x);
  }
  dfs(r2, 0);
  for1(i,n){
  	if(i==r2) continue;
  	cout<<par[i]<<" ";
  }
  cout<<endl;
  return 0;
}