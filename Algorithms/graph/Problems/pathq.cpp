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

int n,q; 
vector<vector<int> > adj(MAXN);
vector <int> b;
int in[MAXN], out[MAXN];
LL di[MAXN], t[2*MAXN], c[MAXN];

void dfs(int i,int p=-1){
  di[i]=(p!=-1?di[p]:0)+c[i];
  b.pb(i);
  in[i] = b.size()-1;
  for(auto j:adj[i])
    if(j!=p) dfs(j,i);
  out[i] = b.size()-1;
}

LL qu(int s){
  LL an = 0;
  for(s+=n;s>0;s>>=1) an+=t[s];
  return an;
}

void up(int l,int r,LL v){
  for(l+=n,r+=n; l<r;l>>=1, r>>=1){
    if(l&1) t[l++]+=v;
    if(r&1) t[--r]+=v;
  }
}


int main(){
  fio();
  cin>>n>>q;
  forn(i,n) cin>>c[i]; 
  forn(i,n-1){
    int u,v; cin>>u>>v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(0);
  //forn(i,n) cout<<i+1<<" "<<di[i]<<endl;
   while(q--){
    int x; cin>>x;
    if(x==1){
      LL s,v; cin>>s>>v;
      s--;
//      cout<<(v-(qu(in[s])+di[s]))<<endl;
      up(in[s],out[s]+1,v-(c[s]));
      c[s] = v;
    }
    else{
      int s; cin>>s;
      s--;
      cout<<(di[s]+qu(in[s]))<<endl;
    }
  }
  return 0;
}

