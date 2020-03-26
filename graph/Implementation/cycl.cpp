#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector <vector<pair<int,int> > > adj(n);
int n,m; 

void dfs(int i, int p){
  if(vis[i]==1){
    cout<<"CYCLE"<<endl;
    exit(0);
  }
  vis[i] = 1;
  for(auto v:adj(i))
    if(v!=p) dfs(v,i);
}

int main(){
  fio();
  cin>>n>>m;
  forn(i,0,m){
    int u,v; cin>>u>>v;
    adj[u].push_back({v,d});
    adj[v].push_back({u,d});
  }  
  dfs(1,-1);
  cout<<"NO CYCLE"<<endl; 
  return 0;
}

