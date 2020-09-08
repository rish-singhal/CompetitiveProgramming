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
    int n; cin>>n;
    vi v(n);
    forn(i,n) cin>>v[i];
    srt(v);
    vector <int> vv;
    for(auto i:v){
      if(vv.empty()) vv.pb(i);
      else{
        int f =0;
        for(auto j:vv){
          if(i%j==0){
            f=1; break;
          }
        }
        if(f==0) vv.pb(i);
      }
    }
    cout<<vv.size()<<endl;
    return 0;
}

