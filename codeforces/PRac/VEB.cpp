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

vector <int> adj[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n; cin>>n;
    vector <int> v(n+5);
    forn(i,n) cin>>v[i];
    for1(i,n-1)
    { int u; cin>>u;
      adj[i].pb(u-1);
      adj[u-1].pb(i);
    }
//    vector <int> clz(1<<n,0);
    //for1(i,(1<<n)-1) clz[i] = __builtin_clz(i);
    vector <int> b(1<<n,1e9);
    b[0] = v[0];
    for1(msk,(1<<n)-1){
      int z = __builtin_ctz(msk);
//      cout<<z<<endl;
      b[msk] = b[msk^(1<<z)] + v[z];
    }
  //  cout<<"yrery"<<endl;
    forn(msk,1<<n){
      int ms = msk;
      for(int j=0;j<n;j++)
        if(msk&(1<<j)){
          for(auto k:adj[j]){
            ms |= 1<<k;
          }
        }
      b[ms] = min(b[msk],b[ms]);
    }
  //  cout<<"ewfwffwfwf"<<endl;
    
    cout<<b[(1<<n)-1]<<endl;
    return 0;
}

