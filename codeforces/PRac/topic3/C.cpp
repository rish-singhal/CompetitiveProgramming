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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}



vector<vector<int>> adj(MAXN), adj2(MAXN);
int vis[MAXN];

void dfs(int u, int c){
  //cout<<u<<" "<<c<<endl;
  vis[u] = c;
	for(auto i:adj2[u])
		if(vis[i]==0) dfs(i,c);
}


int main(){
  fio();
  int n,m; cin>>n>>m;
  int b = 1;
  for1(i,n){
    int x; cin>>x;
    b&=(x==0);
    forn(j,x){
      int z; cin>>z;
      adj[z].pb(i);
    }
  }
  if(b){
    cout<<n<<endl;
    return 0;
  }
  for1(i,m){
    for(auto a:adj[i]){
      for(auto b:adj[i]){
        if(a==b) continue;
        adj2[a].pb(b);
        adj2[b].pb(a);
      }
    }
  }
  //  cout<<"1"<<endl;
  int cnt = 0;
  for1(i,n){
    if(vis[i]==0){
      dfs(i,++cnt);
    }
  }
  cout<<(cnt-1)<<endl;
  return 0;
}