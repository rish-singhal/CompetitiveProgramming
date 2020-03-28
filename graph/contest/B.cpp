#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector <int> > adj(MAXN);
int n;
vector <int> in(MAXN), out(MAXN), vec;

void dfs(int i, int p = -1){
  vec.pb(i);
  in[i] = vec.size()-1;
  for(auto j:adj[i])
    if(j!=p) dfs(j,i);
  out[i] = vec.size()-1;
}



int main(){
  fio();
  int q; cin>>n>>q;
  for(int i=0;i<n-1;i++){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
    } 
  dfs(1);
  vector <LL> an(n+5);
  while(q--){
    LL u,x; cin>>u>>x;
    an[in[u]]+=x;
    an[out[u]+1]-=x;
  }
  for1(i,n)
    an[i]+=an[i-1];
  for1(i,n) 
    cout<<an[in[i]]<<" ";
  cout<<endl;
  return 0;
}

