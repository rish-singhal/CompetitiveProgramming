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
      LL n; cin>>n;
      vector <int> v;
      while(n){
        v.pb(n%10);
        n/=10;
      }
      LL ann = 1e17;
      forn(i,v.size()){
        forn(j,v.size()){
          LL an = 0;
          LL kk = 1;
          forn(k,v.size()){
            if(k==j) continue;
            an+=kk*v[k];
            kk*=10;
          }
          ann = min(ann,an);

        }
      }
      cout<<ann<<endl;
    }
    return 0;
}

