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
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,h;
LL k, d[MAXN], tm[2*MAXN];
pair <int,LL> t[2*MAXN];
vector<LL> a(MAXN);
vector<vector<int> > adj(MAXN);
vector <int> v, in(MAXN), out(MAXN);

void dfs(int i,int p=-1){
  v.pb(i);
  in[i] = v.size() -1;
  for(auto j:adj[i])
    if(j!=p) dfs(j,i);
  out[i] = v.size()-1;
}

void up(int i){
  i+=n; tm[i] = 1;
  while(i>0) {
    i>>=1;
    tm[i] = tm[i<<1|1] + tm[i<<1];
  }
}

LL qu(int l,int r){
  LL an = 0;
  for(l+=n,r+=n; l<r; l>>=1, r>>=1){
    if(l&1) an+=tm[l++];
    if(r&1) an+=tm[--r];
  }
  return an;
}

void lapply(int i, LL v){
  t[i].se += v;
  if(i<n) d[i]+=v;
}

void lpull(int i){
  for(int s=h;s>0;s--){
    int j = i>>s;
    if(d[j]){
      lapply(j<<1, d[j]);
      lapply(j<<1|1, d[j]);
      d[j] = 0;
    }
  }
}

void lpush(int i){
  while(i>1){
    i>>=1;
    t[i] = lcombine(t[i<<1|1] ,t[i<<1]);
  }
}

void lup(int l,int r,LL v){
  int l0 = n+l, r0= n+r-1;
  for(l+=n,r+=n; l<r;l>>=1,r>>=1){
    if(l&1) lapply(t[l++], v);
    if(r&1) lapply(t[--r],v);
  }
  lpush(l0);
  lpush(r0);
}

int lqu(int l, int r){
  l+=n; r+=n;
  lpull(l);
  lpull(r-1);
  pair<int, LL> an={-1,-1};
  for(;l<r;l>>=1,r>>=1){
    if(l&1) an = lcombine(an,t[l++]);
    if(r&1) an = lcombine(an,t[--r]);
  }
  return an;
}

auto lcombine(vector <int,LL> &u, vector <int,LL> &v) -> vector<int,LL> {
  if(u.se==-1 && u.fi==-1) return v;
  if(u.se > v.se) return u;
  else return v;
}

void query1(){
  int u, LL va; cin>>u>>va;
}


void query2(){
      
}

int main(){
  fio();
  cin>>n>>k;
  h = 32 - __builtin_clz(n);
  forn(i,n) cin>>sv[i];
  forn(i,n-1){
    int u,v; cin>>u>>v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(0);
  forn(i,n){
   LL z = sv[v[i]];
   t[i+n] = {i,z>=k?-inf:z};
   tm[i+n] = (z>=k);
  }
  forr(i,n-1){
    t[i] = lcombine(t[i<<1], t[i<<1|1]);
    tm[i] = tm[i<<1] + tm[i<<1|1];
  }
   int q; cin>>q;
   while(q--){
     int t; cin>>t;
     if(t==1){
        query1();
     }
     else{
       query2();
     }
   }
      return 0;
}

