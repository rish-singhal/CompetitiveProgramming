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
vector<vector<pair<int,LL> > > adj(MAXN);
int vis[MAXN];
int act[MAXN];
LL wt[MAXN];
stack <int> s;
 
void dfs(int i, LL b = 0){
  s.push(i);
//  cout<<i<<" ";
  wt[i] = b;
  act[i] = 1;
  //for(auto j:adj[i]) cout<<j.fi<<" ";
 // cout<<endl;
  for(auto u:adj[i]){
   // cout<<u.fi<<" ----- ----"<<i<<endl;
    LL zz = b + u.se - wt[u.fi];
    if(act[u.fi] && zz<=0LL){
      vector <int> v;
//      cout<<"yes"<<endl;
      while(s.top()!=u.fi){
        v.pb(s.top());
     //   cout<<s.top()<<" ---"<<endl;
        s.pop();
      }
 // cout<<"yes2"<<endl;
      reverse(v.begin(), v.end());
      cout<<"YES\n";
      cout<<u.fi<<" ";
      for(auto kk:v) cout<<kk<<" ";
      cout<<u.fi<<endl;
      exit(0);
    }
    
    if(vis[u.fi]==0 && act[u.fi]==0)
    {// cout<<"yo"<<endl;
      dfs(u.fi,b+u.se);
    }
  }
  act[i] =0;
  vis[i] = 1;
  s.pop();
}
 
int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
    int u,v;
    LL w; cin>>u>>v>>w;
    adj[u].pb({v,w});
  }
  for1(i,n) if(!vis[i]) dfs(i);
  cout<<"NO\n";
  return 0;
}

