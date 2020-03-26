#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector <int> > adj(MAXN);
int n,m;
vector <int> tp;
int vis[MAXN], ac[MAXN];

void dfs(int i){
  vis[i] =1;
  ac[i] = 1;
  for(auto v:adj[i])
  {
    if(ac[i]) {
      cout<<-1<<endl;
      exit(0);
    }
   if(vis[i]!=0) dfs(i);
  }
  ac[i]=0;
  tp.pb(i);
}

int main(){
  fio();
  cin>>n>>m;
  for(int i=0;i<n;i++){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
  }
  for(int i=1;i<=n;i++) 
    if(!vis[i]) dfs(i);
  reverse(tp.begin(), tp.end());
  for(auto i:tp) cout<<i<<" ";
  cout<<endl;
  return 0;
}

