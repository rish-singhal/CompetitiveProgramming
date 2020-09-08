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
const LL mm = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL k,n; cin>>n>>k;
    vector<LL> an(k+1);
    map<int,LL> m;
    forn(i,n){
        LL p; cin>>p;
        m[p]++;
    }
    vector <LL> zz;
    for(auto i:m) zz.pb(i.se);
    if(k>=zz.size()){
      LL ann = 1;
      for(auto i:zz){
        ann = (ann*(1+i))%mm;
      }
        cout<<ann<<endl;
      return 0;
    }
    an[0] = 1, an[1] = zz[0];
    for(int i=1;i<zz.size();i++){
          vector <int> ch(k+1);
          for1(j,k) ch[j] = an[j-1]*zz[i]%mm;
          forn(j,k+1) an[j] = (an[j] + ch[j])%mm;
        }
    LL ann = 0;
    forn(i,k+1) ann = (ann + an[i])%mm;
    cout<<ann<<endl;
    return 0;
}

