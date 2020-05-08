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
const int MAXN = (1<<11) +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n;
vector <vector <pair<int, int> > > adj(MAXN);
int vis[MAXN], co[MAXN];
int ann;

void dfs(int u, int c){
  co[u] = c;
  vis[u] = 1;
  for(auto i:adj[u]){
    int cc = i.fi, vv = i.se;
    if(vis[vv]==1 && co[vv]!=(cc^c)){
      ann = 0;
    }
    if(!vis[vv]) dfs(vv, cc^c);
  }
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	cin>>n;
  	ann = 1;
  	forn(i,MAXN) {
  		adj[i].clear();
      vis[i] = 0;
      co[i] =0;
  	}
  	int a[MAXN][MAXN], b[MAXN][MAXN]; 
  	forn(i,n) forn(j,n) cin>>a[i][j];
  	forn(i,n) forn(j,n) cin>>b[i][j];
  	forn(i,n){
  		forn(j,n){
  			if(a[i][j]==b[i][j] && a[j][i]==a[i][j] && b[i][j]==b[j][i])
  			 continue;
  			if(a[i][j]==b[i][j] && a[j][i]==b[j][i])
  					{
              adj[i].emplace_back(0,j);
              adj[j].emplace_back(0,i);
              continue;
            }
  			if(a[j][i]==b[i][j] && a[i][j]==b[j][i])
  					{
              adj[i].emplace_back(1,j);
              adj[j].emplace_back(1,i);
              continue;
            }
  				cout<<"No\n";
  				ann = 0;
  				break;
  			}
        if(ann==0) break;
  		}
  	if(ann==0) continue;
  	forn(i,n) if(!vis[i]) dfs(i, 0);
    if(ann) cout<<"Yes\n";
    else cout<<"No\n";
  }
  return 0;
}