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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      int n,m; cin>>n>>m;
      int mt[m][n];
      vector <int> best(1<<n,-1e9);
      best[0]= 0;
      forn(i,n)forn(j,m) cin>>mt[j][i];
      int ctz[1<<n];
      for1(i,(1<<n)-1) ctz[i]=__builtin_ctz(i);
      int mx[m];
      forn(i,m) mx[i] = *max_element(mt[i],mt[i]+n);
      vi ord(m);
      iota(all(ord),0);
      sort(all(ord),[&](int i,int j){ return mx[i]>mx[j];});
      forn(i,m){
        if(i>n+1) break;
        int ci = ord[i];
        vector <int> val(1<<n,0);
        for1(msk,(1<<n)-1){
            int z = ctz[msk];
            val[msk] = val[msk^(1<<z)] + mt[ci][z];
        }
        forn(j,n)
          forn(k,1<<n){
            int kk = (k>>1)|((k&1)<<(n-1));
            val[k] = max(val[k],val[kk]);
          }
        for(int msk=(1<<n)-1;msk>=0;msk--){
          int rem = msk^((1<<n)-1);
          for(int lf= rem;lf;lf=(lf-1)&rem)
            best[lf|msk] = max(best[lf|msk], best[msk] + val[lf]);
        }
      }
      cout<<best[(1<<n)-1]<<endl;
    }
     return 0;
}

