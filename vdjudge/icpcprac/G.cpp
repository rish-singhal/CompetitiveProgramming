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
    freopen ("looking.in", "r", stdin);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      int n,tt; cin>>n>>tt;
      vector <int> sz(21);
      forn(i,n){
        int k; cin>>k;
        int p = 0;
        while(k){
          if(k&1){
              sz[p]++;
          }
          k>>=1;
       p++;
        }
      }
      LL an = 0;
      for(int i = 20;i>=0;i--){
        an += (sz[i]>0)*(1<<i);
      }
      cout<<an<<endl;
    }
    return 0;
}

