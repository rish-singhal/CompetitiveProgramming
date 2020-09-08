#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

int dsu[200005];
int par(int u){
  return dsu[u]<0? u: dsu[u]=par(dsu[u]);
}
LL an =0;
void join(int u, int v){
  u = par(u);
  v = par(v);
  if(u==v) return;
  an += (LL)dsu[u]*(LL)dsu[v];
  if(dsu[u]<dsu[v]) swap(u,v);
  dsu[v]+=dsu[u];
  dsu[u] = v;
}
int main()
{
   memset(dsu,-1,sizeof(dsu));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n,m; cin>>n>>m;
    vector < pair<int, pair<int,int> > > ed(m);  
    forn(i,n-1){
       int u,v, w;
       cin>>u>>v>>w;
       ed.pb(make_pair(w,make_pair(u,v)));
    }
    vector <pair<int,int> > q(m);
    vector <LL> ans(m);
    forn(i,m){
      int a; cin>>a;
      q[i] = make_pair(a,i);
    }
    srt(q);
    srt(ed);
    int c = 0;
    for(auto wt:q){
       while( c < ed.size() && wt.fi >= ed[c].fi ){
         join(ed[c].se.fi, ed[c].se.se);
          c++;
       }
       ans[wt.se] = an;
    }
    forn(i,m) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}

