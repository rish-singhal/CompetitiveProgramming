#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 1e5+5;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int sz[MAXN];
vector <vector <int> > adj(MAXN);

int dfs(int u, int p){
   int &x = sz[u] = 1;
   for(auto i:adj[u])
    if(i!=p) x+=dfs(i,u);
  return x;
}


int main(){
  fio();
  int n; cin>>n;
  forn(i,0,n-1){
    int u,v;cin>>u>>v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(0,-1);
  forn(i,0,n){
    cout<<i+1<<" : "<<sz[i]<<endl;
  }
  return 0;
}

