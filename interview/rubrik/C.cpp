#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < (n); i++)
const int MAXN = 2e5 + 5;
const int INF = 1e9;

vector<int> adj[MAXN];
int col[MAXN], mrk[MAXN], depth[MAXN];
int s, d;
vector<int> dp(8, INF);
int omsk = 0;

void dfs(int u, int p, int msk){
  msk |= 1<<col[u];
  if(p) depth[u] = depth[p] + 1;
  for(auto v:adj[u])
    if(v!=p){
      dfs(v, u, msk);
      mrk[u] |= mrk[v];
    }
  if(u == d){
    mrk[u] = 1;
    omsk = msk;
  }
}

void dfs2(int u, int p, int lcp, int msk){
    if(msk&(1<<col[u])){
      msk ^= (1<<col[u]);
      dp[msk] = min(dp[msk], 2*(depth[u] - depth[lcp]));
    }
    for(auto v: adj[u])
      if(v!=p) dfs2(v, u, mrk[u]?u:lcp, msk);
}

int main(){
  int n; cin>>n;
  forn(i,n){
    int x; string s; cin>>x>>s;
    if(s=="Red") col[x] = 1;
    else if(s == "Green") col[x] = 2;
  }
  forn(i,n-1){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin>>s>>d;
  dfs(s, 0, 0);
  int ans = 3 + depth[d];
  if(omsk == 7){
    cout<<ans<<endl;
    return 0;
  }
  int msk = 7 ^ omsk;
  dfs2(s, 0, s, msk);
  if(__builtin_popcount(msk) == 1){
    cout<<(ans + dp[0])<<endl;
    return 0;
  }
  int delta = dp[0];
  for(int msk2 = msk; msk2 > 0; msk2 = (msk2-1)&msk)
    delta = min(delta, dp[msk2] + dp[msk2^msk]);
  cout<<(ans + delta)<<endl;
  return 0;
}
