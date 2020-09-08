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
      int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
      int x = (a/c)+(a%c!=0);
      int y = (b/d)+(b%d!=0);
      if(x+y<=k){
        cout<<x<<" "<<y<<endl;
      }
      else{
        cout<<-1<<endl;
      }
    }
    return 0;
}

