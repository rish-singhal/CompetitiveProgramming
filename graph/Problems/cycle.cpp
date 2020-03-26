#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
 
const int MAXN = 25005;
 
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n,m; 
vector<vector<pair<int,int> > > adj(MAXN);
int vis[MAXN];
int act[MAXN];
stack <int> s;
 
void dfs(int i, int b = 0){
  s.push(i);
  act[i] = 1;
  //  cout<<i<<" "<<p<<" "<<b<<endl;
  for(auto u:adj[i]){
    b |= u.se<0;
    if(act[u.fi] && b){
      vector <int> v;
      while(!s.empty()){
        v.pb(s.top());
        s.pop();
      }
      reverse(v.begin(), v.end());
      cout<<"YES\n";
      cout<<u.fi<<" ";
      for(auto kk:v) cout<<kk<<" ";
      cout<<u.fi<<endl;
      exit(0);
    }
    if(!vis[u.fi])
      dfs(u.fi,b);
  }
  act[i] = 0; 
  vis[i] = 1;
  s.pop();
}
 
int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
    int u,v,w; cin>>u>>v>>w;
    adj[u].pb({v,w});
  }
  for1(i,n) if(!vis[i]) dfs(i);
  cout<<"NO\n";
  return 0;
}
