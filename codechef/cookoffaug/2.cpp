#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < (n); i++)
const int MAXN = 1e5+ 5;
typedef long long LL;

int n;
string s;
vector<int> adj[MAXN];
vector<int> co;
LL cnt;

void dfs(int u, int p){
  if(u) co[u] = 1^co[p];
  cnt += co[u];
  //cout<<cnt<<" --"<<endl;
  for(auto i:adj[u])
    if(i!=p) dfs(i, u);
}

LL dp[MAXN];
LL an = 0;

void dfs2(int u, int p, int pp){
  for(auto i: adj[u]){
    if(i!=p) dfs2(i, u, pp^1);
  }
  if(dp[u]!=pp){
    LL diff = pp - dp[u];
    dp[u] += diff;
    dp[p] -= diff;
    an += abs(diff);
  }
}

void solve(){
  cin>>n;
  cnt = 0;
  co.resize(n);
  for(auto &i:co) i = 0;
  forn(i,n) adj[i].clear();
  forn(i,n-1){
    int u,v; cin>>u>>v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin>>s;
  dfs(0, -1);
  int cn = 0;
  for(auto i:s) cn+= (i=='0');

  LL ans = 1e17;
  if(cn == cnt) {
    an = 0;
    forn(i,n) dp[i] = (s[i]-'0');
    dfs2(0, -1, 1);
    ans = min(ans, (LL)an);
  }
  if((n - cn) == cnt){
    //cout<<"ye"<<endl;x
    an = 0;
    forn(i,n) dp[i] = (s[i]-'0');
    dfs2(0, -1, 0);
    ans = min(ans, (LL)an);
  }
  if(ans==1e17) cout<<-1<<endl;
  else cout<<(ans)<<endl;
  return;
}

int main(){
  int t; cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
