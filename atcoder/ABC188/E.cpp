#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN = 2e5 + 5;
const LL INF = 1e17;
LL a[MAXN], tpp[MAXN], vis[MAXN];
vector <LL> adj[MAXN];
LL ans;
vector <LL> tp;

void dfs(int i){
  if(vis[i]) return;
  vis[i] = 1;
  for(auto x : adj[i])
    if(!vis[x])
      dfs(x);
  tp.push_back(i);
}


int main(){
  int n, m; cin>>n>>m;
  for(int i = 0; i < n; i ++)
    cin >> a[i];
  for(int i = 0; i < m; i++)
  {
    int u, v; cin>>u>>v;
    u--, v--;
    adj[u].push_back(v);
  }
//  for(int i = 0; i < n; i++)
  //  if(!vis[i])
    //  dfs(i);
 // reverse(tp.begin(), tp.end());

  vector<LL> dp(n, INF);
  LL ans = -2*INF;
  for(int i = 0; i < n; i ++){
//    cout << i << " " << dp[i] << endl;
    ans = max(ans, a[i] - dp[i]);
    for(auto x: adj[i])
      dp[x] = min(dp[x], min(a[i],dp[i]));
  }

  cout << ans << endl;
  return 0;
}

  
