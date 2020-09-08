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

int v[1000005];
vector <int > ad[1000005];
int up[1000005][32];
int mv[1000005];
int cnt[1000005];
int n, lgn;
void dfs(int u,int p){
  mv[u] = max(v[u],mv[p]);
  cnt[u] = cnt[p] + (v[u]>mv[p]);
  up[u][0] = p;
  for(int i=1;i<=lgn;i++)
    up[u][i] = up[up[u][i-1]][i-1];
  for(auto vv:ad[u])
    if(vv!=p) dfs(vv,u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      cin>>n;
      lgn = ceil(log2(n)) +1;
      
      for1(i,1000005) ad[i].clear(); //ad.resize(n+10);
      for1(i,n) cin>>v[i];
      for(int i =2;i<=n;i++){
        int k; cin>>k; ad[i].pb(k); ad[k].pb(i);
      }
      dfs(1,0);
 //     for1(o,n) cout<<mv[o]<<" " ;
//      cout<<endl;
      int q; cin>>q;
      int pr = 0;
      forn(o,q){
        int vv,w; cin>>vv>>w;
        vv^=pr, w^=pr;
        int pv = vv;
        if(mv[vv] <= w)
          {
            cout<<0<<endl;
            pr=0;
            continue;
          }
        if(mv[1] > w)
        { cout<<cnt[pv]<<endl;
           pr = cnt[pv]; 
        continue;
         }
        for(int k=lgn;k>=0;k--)
          if(mv[up[vv][k]] > w)
              vv = up[vv][k];
        pr = cnt[pv] - cnt[up[vv][0]];
        cout<<pr<<endl; 
      }

    }    
    return 0;
}

