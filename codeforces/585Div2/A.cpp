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
    int a1,a2,k1,k2,n; cin>>a1>>a2>>k1>>k2>>n;
    LL kk = (k1-1)*a1 + (k2-1)*a2;
    LL mi = 0, ma =0;
    if(n>kk) mi = min((LL)n-kk,(LL)a1+a2);
    if(k2>k1){
      LL z = n/k1;
      if(z >= a1) {
        ma += a1;  
        n-=a1*k1;
      }
      else{
        ma +=z;
        n = 0;
      }
     z = n/k2;
     if(z>=a2){
       ma += a2;
       n-=a2*k2;
     }
     else{
       ma+=z;
       n=0;
     }
    }
    else {
      LL z = n/k2;
      if(z >= a2) {
        ma += a2;  
        n-=a2*k2;
      }
      else{
        ma +=z;
        n = 0;
      }
     z = n/k1;
     if(z>=a1){
       ma += a1;
       n-=a1*k1;
     }
     else{
       ma+=z;
       n=0;
     }
    }
 cout<<mi<<" "<<ma<<endl;
      
    return 0;
}

