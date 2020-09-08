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
      LL a,b,c; cin>>a>>b>>c;
      if(a <= b) {
        c-=b-a+1;
        if(c<0){
          cout<<0<<endl;
          continue;
        }
        else if(c==1)
        {
          cout<<1<<endl;
          continue;
        }
        a = b+1;
      }
      LL k = a-b;
      LL zz = c + k;
      if(zz&1) cout<<min(c+1,((zz/2)+1))<<endl;
      else cout<<min(c+1,((zz/2)))<<endl;
    }
    return 0;
}

