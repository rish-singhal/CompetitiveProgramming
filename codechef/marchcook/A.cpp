#include <bits/stdc++.h>
using namespace std;
#define forn(i,n)  for(int i=0;i<n;i++)
typedef unsigned long long LL;
const LL m = 1e9 +7;

LL po(LL a, LL n){
  if(n==0) return 1;
  LL an = po(a,n/2);
  an = (an*an)%m;
  if(n&1) return (an*a)%m;
  return an%m;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
     LL an = 1;
    LL k = 0;
    int b = 0;
    forn(i,n){
      LL z; cin>>z;
      if( (z&k) != k){
        b = 1;
      }
      an = (an*po(2,__builtin_popcountll(z) - __builtin_popcountll(z-k)))%m;
      k = z;
    }
    if(b==1) cout<<0<<endl;
    else cout<<(an)%m<<endl;
  }
  return 0;
}
