#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 1e5;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int> > adj(MAXN);
int n,m, b =1, vis[MAXN], act[MAXN];
vector <int> tp;

void dfs(int i){
  if(act[i]){
    b= 0; return;
  }
  act[i] = 1;
  vis[i] = 1;
  for(auto v:adj[i]){
    if(!vis[v])  
      dfs(v);
  }
  act[i] = 0;
  tp.pb(i);
}
int main(){
  fio();
  cin>>n>>m;
  forn(i,0,m){
    int u, v; cin>>u>>v;
    adj[u].pb(v);
  }
  forn(i,1,n+1){
    if(!vis[i]) dfs(i);
  }
  reverse(tp.begin(),tp.end());
  for(auto i:tp)cout<<i<<" ";
  cout<<endl;
  return 0;
}

