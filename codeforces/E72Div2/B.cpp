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
      LL n,x; cin>>n>>x;
      vector<pair<int,int> > v(n);
      LL m = -1;
      LL m2 = -1;
      forn(i,n){
        LL a,b; cin>>a>>b;
        m2 = max(m2,a-b);
        m = max(m,a);  
      }
      if( m >= x) {
        cout<<1<<endl;
        continue;
      }
      if( m2 <=0 ) {
        cout<<-1<<endl;
        continue;
      }
      LL zz =( ( x - m)/m2 ) + 2 - ( (x-m)%m2==0);
      cout<<zz<<endl;
 
    }return 0;
}

