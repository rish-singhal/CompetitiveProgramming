#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 500005;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n, sz[MAXN];
LL dp[MAXN],ans[MAXN];
LL ip[MAXN];
vector <vector<pair<int, LL> > > v(MAXN);

int dfs(int u, int p=-1){
  int &x = sz[u] = 1;
  LL &d = dp[u] = 0;
  for(auto i:v[u]){
    if(i.fi!=p){
      x+=dfs(i.fi,u);
      d+=i.se*sz[i.fi] + dp[i.fi];
    }
  }
  return x;
}

void dfs2(int u,int p=-1,LL e=-1){
  if(p==-1) ans[u] = ip[u]*dp[u];
  else{
      dp[p]-=e*sz[u] + dp[u];
      dp[u] +=e*(n-sz[u]) + dp[p]; 
    ans[u]=dp[u]*ip[u];  
  }
  cout<<u<<" : "<<dp[u]<<" "<<ans[u]<<endl;
  for(auto i:v[u]){
      if(i.fi!=p) dfs2(i.fi,u, i.se);
  }
  if(p!=-1){
    dp[u] -= e*(n-sz[u]) + dp[p];
    dp[p] += e*sz[u] + dp[u];
  }
}

int main(){
  fio();
  cin>>n;
  forn(i,0,n) cin>>ip[i];
  forn(i,0,n-1){
    int a,b; cin>>a>>b;
    LL w; cin>>w;
    v[a].pb({b,w});
    v[b].pb({a,w});
  }
  dfs(0);
  cout<<"yay"<<endl;
  dfs2(0);
  forn(i,0,n) cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}

