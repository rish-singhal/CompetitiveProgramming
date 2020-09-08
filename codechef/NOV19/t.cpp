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
    map <LL,LL> m;
    for1(i,100000){
      m[i*i] = 1;
    }
    for1(i,9){
      for1(j,9){
        for1(k,9){
          for1(p,9){
            for1(o,9){
              for1(s,9){
              if(m.find(i*i + j*j + k*k+p*p + o*o + s*s)!=m.end()){
            cout<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<o<<" "<<s<<endl;
            return 0;
          }
              }
            }
          }
        }
      }
    }
    return 0;
}

