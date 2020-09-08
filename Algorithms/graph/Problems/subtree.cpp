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

LL t[1<<20];
vector <vector <int> > adj(MAXN);
int n,q;
int in[MAXN], out[MAXN];
vector <int> v;

void dfs(int u,int p=-1){
  v.pb(u);
  in[u] = v.size() -1;
  for(auto i:adj[u])
    if(i!=p) dfs(i,u);
  out[u] = v.size() -1;
}

void up(int i, LL v){
  for(i+=n, t[i] = v;i>1;i>>=1)
    t[i>>1] = t[i] + t[i^1];
}

LL qu(int l, int r){
  LL an  =0;
  for(l+=n, r+=n; l<r; r>>=1, l>>=1){
    if(l&1) an+=t[l++];
    if(r&1) an+=t[--r];
  }
  return an;
}

int main(){
  fio();
  cin>>n>>q;
  vector <LL> va(n);
  forn(i,n) cin>>va[i];
  for(int i=0;i<n-1;i++){
    int u,v; cin>>u>>v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  } 
  dfs(0);
  
  forn(i,n) t[n+i] = va[v[i]];
  for(int i =n-1; i>=1;i--)  t[i] = t[i<<1] + t[i<<1|1];
  while(q--){
    int x; cin>>x;
    if(x==1){
      LL v,s; cin>>s>>v;
      up(in[s-1],v);
    }
    else{
      int s; cin>>s;
      s--;
      cout<<qu(in[s], out[s]+1)<<endl;
    }
  }
  return 0;
}

