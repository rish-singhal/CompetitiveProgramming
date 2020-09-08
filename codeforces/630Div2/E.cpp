#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;
const LL mod = 998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
  if (n==0) return 1;
  LL an = po(a,n/2);
  an = (an*an)%mod;
  if(n&1) return an*a%mod;
  return an;
}

int main(){
  fio();
  LL l,r,n,m; cin>>n>>m>>l>>r;
  LL e = (r+1)/2 - (l)/2;
  LL o = -l+r+1-e;
  LL p = n*m;
  if(p&1) cout<<po(e+o,p)<<endl;
  else{
    LL an = (po(e+o,p) + po(e-o,p))%mod;
    an = an*po(2,mod-2)%mod;
    cout<<an<<endl;
  }
  return 0;
}

