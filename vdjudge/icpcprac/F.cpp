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
const LL m = 1e6;
const LL mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t;
    cin>>t;
    while(t--){
      int n; cin>>n;
      vector<LL> mm(m+5);
      vector <LL> v(n);
      forn(i,n){
        int k;
        cin>>k;
        mm[k]=1;
      }
     LL an = 0;
     for1(i,m){
        for(int j=2*i;j<=m;j+=i)
          if(mm[j]) mm[j] = (mm[j] + mm[i])%mod;
        an = (an + mm[i])%mod;
     } 
     cout<<an<<endl;
    }
        
    return 0;
}

