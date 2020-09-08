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
const LL mm = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector <LL> f(n+1);
    f[0] = 1;
    for1(i,n) f[i] = f[i-1]*i%mm;
    vector <pair<LL,LL> > v(n);
    map<LL,LL> m,m1;
    forn(i,n){
      cin>>v[i].fi>>v[i].se;
      m[v[i].fi]++;
      m1[v[i].se]++;
    }
    LL an1 = 1;
    for(auto i:m)
      an1 = an1*f[i.se]%mm;
    LL an2 = 1;
   for(auto i:m1)
      an2 = an2*f[i.se]%mm;
    srt(v);
    LL an = (f[n] - an1 - an2 )%mm;
    if(an < 0) an+=mm;
    for1(i,n-1) if(v[i-1].se > v[i].se){
      
      cout<<an<<endl;
      return 0;
    }
    map< pair<LL,LL>,LL > p;
    for(auto i:v){
      p[i]++;
    }
    LL an3 = 1;
    for(auto i:p){
      an3=an3*f[i.se]%mm;
    }
    an = (an + an3)%mm;
    if(an<0) an = mm + an;
    cout<<an<<endl;
    return 0;
}
