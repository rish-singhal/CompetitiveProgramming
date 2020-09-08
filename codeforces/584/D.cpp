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
int n,m; 
vector <int> adj[100005];
LL an =0;
int vis[100005];

void dfs(int u){
  if(vis[u]) return;  
  vis[u] = 1;
    for(auto i:adj[u]){
      if(vis[i]) an++;
      dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin>>n>>m;
    forn(i,m){
      int a,b; cin>>a>>b;
      adj[b].pb(a);
      adj[a].pb(b);
    }
    for(int i=1;i<=n;i++)
      if(!vis[i]) dfs(i);
    cout<<(an-m)<<endl;
    return 0;
}

