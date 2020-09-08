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
const LL m = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      LL a,b,c; cin>>a>>b>>c;
      a--,c--;
      LL an = 0;
      for(LL i=1;i<=b;i++){
        an = ( an + max(0LL,a-i)*max(0LL,c-i))%m;
        for(LL j=1;j<=min(i,a);j++)
          an = ( an + max(0LL,(c-(LL)(i*1.0*i/j))))%m;
        for(LL j=1;j<=min(i,c);j++)
          an = ( an + max(0LL,(a-(LL)(i*1.0*i/j))))%m;
      }
      cout<<an<<endl;
    }
    return 0;
}

