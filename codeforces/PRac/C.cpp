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
    LL n,I; cin>>n>>I;
    map <int,LL> m;
    vector <int > v;
    forn(i,n){
      int k; cin>>k;
      m[k]++;
    }
    LL an =0;
    for(auto i:m){ v.pb(i.se); an+=i.se;}
    LL k = m.size();
    int l = 0, r= v.size()-1;
    LL kk =  k;
    while(1){
      if(ceil(log2(kk))*n<=I*8) break;
      kk--;
    }
    LL res = 0;
    forn(i,kk) res+=v[i];
    LL cc = res;
    for(int i=kk;i<n;i++)
    { 
      cout<<(i-kk)<<endl;
      cc += v[i] - v[i-kk];
      res = max(res,cc);
    }

    cout<<(an - res)<<endl;

    return 0;
}

