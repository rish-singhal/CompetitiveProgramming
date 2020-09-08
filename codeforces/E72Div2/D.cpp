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
vector<int> vis;
vector<pair<int,int> > pp;
int cc[5005];
map<pair<int,int>, int> mm;
vector<int> adj[5005];
int tt = 0;

void dfs(int u, int c){
    if(vis[u]) return;
    vis[u] = 1;
    for(auto v:adj[u]){
      if(vis[v]==1){
            cc[mm[{u,v}]] ^= c;
            tt =1;
      }
      if(vis[v]== 2)continue;
      dfs(v,c);
    }
    vis[u] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin>>n>>m;
    vis.resize(n+1);
    pp.resize(m);
    forn(i,m){
        int u,v; cin>>u>>v;
        pp[i] = {u,v};
        mm[{u,v}] = i;
        adj[u].pb(v);
    }
    for1(i,n)
      if(!vis[i]) dfs(i,1);

    cout<<(tt?2:1)<<endl;
    forn(i,m) cout<<(cc[i]?2:1)<<" ";
    cout<<endl;
       
    return 0;
}

