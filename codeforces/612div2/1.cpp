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
      int n; cin>>n;
      string s; cin>>s;
      int m = 0;
      int b = 0, c = 0;
      for(auto i:s){
        if(i=='A'){ 
          b = 1;
          m = max(m,c);
          c = 0;
        }
        else{
          if(b) c++;
        }
      }
      m = max(m,c);
      cout<<m<<endl;
    }

    return 0;
}

