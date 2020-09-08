#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 1e5 + 5;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector <vector<int> > adj(MAXN);
int d = -1, vv = -1;

void dfs(int u, int p, int di=0){
  if(d < di) {
     d = di;
     vv = u;}
  for(auto v:adj[u])
    if(v!=p)
      dfs(v,u,di+1);
}

int main(){
  fio();
  int n; cin>>n;
  forn(i,0,n-1){
    int u,v; cin>>u>>v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,0);
  dfs(vv,0);
  cout<<d<<endl;
  return 0;
}

