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
      LL n,p; cin>>n>>p;
      vector <LL> v(n),an(n);
      forn(i,n) cin>>v[i];
      bool b = 0;
      forn(i,n){
        if(p%v[i]!=0){
            an[i] = (p/v[i]) + 1;
        b = 1;
        break;
        }
      }
      if(b){
        cout<<"YES ";
        for(auto i:an) cout<<i<<" ";
        cout<<endl;
        continue;
      }

      b = 0;
      forn(i,n-1){
        if(v[i]*2 > v[i+1]){
          an[i] = (p/v[i]) - 1;
          an[i+1] = 1;
          b = 1;
          break;
        }
      }
      if(b){
        cout<<"YES ";
        for(auto i:an) cout<<i<<" ";
        cout<<endl;
        continue;
      }
      else 
      {
        LL kp = p;
        b = 0;
        forn(i,n){
         int k = n - i -1;
         if(kp%v[k]!=0){
           an[k] =(kp/v[k]) + 1;
           b = 1;
           break;
         }
         an[k] = (kp/v[k]) - 1;
         kp = kp - an[k]*v[k];
        }
        if(!b)cout<<"NO\n";
        else{
        cout<<"YES ";
        for(auto i:an) cout<<i<<" ";
        cout<<endl;
        continue;
        }
      }
    }
    return 0;
}

