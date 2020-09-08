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
LL f[100005], fi[100005];
const LL m = 1e9+7;

LL minv(LL a, LL n){
  if(n==0) return 1;
  LL an = minv(a,n/2);
  an = (an * an)%m;
  if(n&1) an = (an*a)%m;
  return an;
}

LL ncr(LL a, LL b){
  //return (((f[a]*fi[b])%m)*fi[a-b])%m;
  return (f[a]*minv(f[b],m-2)%m)*minv(f[a-b],m-2)%m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;    
    f[0] = f[1] = fi[0] = fi[1] =  1;
    for(int i=2;i<100005;i++) f[i]=i*f[i-1]%m;
    for (int i=2; i<100005; ++i)
	     fi[i] = (m - (m/i) * fi[m%i] % m) % m;   
    LL t; cin>>t;
    while(t--){
      LL n; cin>>n;
      string a,b; cin>>a>>b;
      LL ca = 0, cb = 0;
      for(auto i:a) ca += i=='1';
      for(auto i:b) cb += i=='1';
      LL mi = abs(ca-cb);
      LL ma = ca + cb;
     
      if(ca+cb > n) ma = 2*n  - ma;
//      cout<<mi<<" " <<ma<<endl;
      LL an = 0;
      for(LL i = mi;i<=ma;i+=2)
        an =(an+ ncr(n,i))%m;
      cout<<an<<endl;
      }

    return 0;
}

