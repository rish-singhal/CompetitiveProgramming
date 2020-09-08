#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
vector <int> adj[1005];
int bb = 0;
int kv[1005],vis[1005];

void dfs(int u,int q){
  if(vis[u]) return;
  vis[u] =1;
  kv[u] = q;
  for(auto i :adj[u]){
    if(vis[i]){
      if(kv[i]==kv[u])
      bb = 1;
      continue;
    }
    dfs(i,q*-1);
  }
  return;
}
    
  

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      memset(vis, 0, sizeof vis);
      memset(kv,0,sizeof kv);
      forn(i,1005) adj[i].clear();       
      int n; cin>>n;
      map <pair<LL,LL>, LL > m,va;
      vector <pair<LL,LL> > v;
      forn(i,n){
        LL l,r,kk; cin>>l>>r>>kk;
        v.pb({l,r});
        m[{l,r}] = kk;
      }
      int nn = v.size();
      srt(v);
      forn(i,nn){
        for(int j=i+1;j<nn;j++){
//          cout<<"wd "<<i<<" "<<j<<endl; 
          if(m[v[i]]!=m[v[j]]) continue;
          if(v[i].se < min({v[j].se,v[j].fi}))
            continue;
          if(v[i].fi > max({v[j].se,v[j].fi}))
            continue;
          adj[i].pb(j);
          adj[j].pb(i);
        }
      }
      forn(i,nn) if(!vis[i]) dfs(i,1);
      if(bb) cout<<"NO\n";
      else cout<<"YES\n";
    }
    return 0;
}

