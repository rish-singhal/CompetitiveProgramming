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
vector <vector <int> > adj(MAXN);
vector <int> v(MAXN);
int an = 0, n, m;

void dfs(int u, int p, int cnt){
  if(adj[u].size()==1 && u!=1 && cnt<=m) an++;
  for(auto i:adj[u]){
    if(i!=p){
      if(v[i]==0) dfs(i,u,0);
      else{
        if(cnt+1<=m) dfs(i,u,cnt+1);
      }
    }
  }
}


int main(){
  fio();
   cin>>n>>m;
  forn(i,1,n+1) cin>>v[i];
  forn(i,1,n){
    int a,b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  } 
  dfs(1,0,v[1]);
  cout<<an<<endl;
  return 0;
}

