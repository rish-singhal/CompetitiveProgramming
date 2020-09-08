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
    LL n,p,w,d; cin>>n>>p>>w>>d;
    if(p==0){
      cout<<0<<" "<<0<<" "<<n<<endl;
      return 0;
    }
    int b =0; LL x,y,z;
    forn(i,w){
      if( (p-i*d)%w==0){
        y = i;
        x = (p-i*d)/w;
        z = n - x- y;
        if( x>=0 && z>=0 && x*w + y*d - p ==0){
          b  =1;
          break;
        }
      }
    }
    
    if(b==1)cout<<x<<" "<<y<<" "<<z<<endl;
    else cout<<-1<<endl;
    return 0;
}

