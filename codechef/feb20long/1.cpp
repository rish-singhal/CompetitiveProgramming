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
    int t; 
    cin>>t;
    while(t--){
      LL n,p; cin>>n>>p;
      vector <LL> v(n), sr(n);
      map <LL,LL> an;
      forn(i,n){
        cin>>v[i];
        sr[i] = v[i];
      }
      bool b = 0;
      forn(i,n)
        if(p%v[i]!=0)
        {
          an[v[i]] = (p/v[i]) + 1;
          b = 1;
          break;
        }
      
      if(b==1){
        cout<<"YES ";
        for(auto i:v)cout<<an[i]<<" ";
        cout<<endl;
        continue;
      }
      else{
        srt(sr);
        b = 0;
        forn(i,n-1){
            if(sr[i]==1) continue;
            if(sr[i]*2 > sr[i+1]){
              an[sr[i]] = (p/sr[i]) - 1;
              an[sr[i+1]] = 1;
              b = 1;
              break;
            }
        }
        if(b==0) cout<<"NO\n";
        else{
          cout<<"YES ";
          for(auto i:v){
            cout<<an[i]<<" ";
          }
          cout<<endl;
        }
      }
    }

    return 0;
}

