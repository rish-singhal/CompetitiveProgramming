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
      int a,b, c; cin>>a>>b>>c;
      LL an = 0;
      if(c>=2*b){
        an+=3*b;
        cout<<an<<endl;
        continue;
      }
      else{
        an+=(c/2)*3;
        b-=(c/2);
        if(b>=2*a){
          an+=3*a;
          cout<<an<<endl; 
          continue;
        }
        else{
          an+=(b/2)*3;
          cout<<an<<endl;
          continue;
        }
      }
    }
    return 0;
}

