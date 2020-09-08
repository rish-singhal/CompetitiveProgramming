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

int n,m;
vector <vector<pair<int,LL> > > adj(MAXN); 
int p[MAXN];
LL d[MAXN];

int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
    int u,v; LL w;cin>>u>>v>>w;
    adj[u].pb({v,w});
  }
  int x;
  forn(i,n){
     x = -1;
    for1(u,n)
      for(auto v:adj[u])
        if(d[u] + v.se < d[v.fi]){
          d[v.fi] = d[u] + v.se;
          p[v.fi] = u;
          x = v.fi;
        }
  }
  if(x==-1) cout<<"NO\n";
  else{
      forn(i,n)  x = p[x];
      vector <int> cy;
      for(int v= x;; v = p[v]){
        cy.pb(v);
        if(v==x && cy.size()>1)
          break;
      }
      reverse(all(cy));
      cout<<"YES\n";
      for(auto i:cy) cout<<i<<" ";
      cout<<endl;
  }
  return 0;
}

