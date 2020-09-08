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
const int MAXN = 2e5 +5;
const LL mm =  998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%mm;
	if(n&1) an = (an*a)%mm;
	return an;
}

LL f[MAXN], fi[MAXN];

LL ncr(LL n, LL m){
	LL aa =  (f[n]*fi[n-m])%mm;
	aa = (aa*fi[m])%mm;
	return aa;
}

int main(){
  fio();
  LL n,m; cin>>n>>m;
  LL k; cin>>k;
  f[0] = 1;
  fi[0] = 1;
  for1(i,n+10){
  	f[i] = (i*f[i-1])%mm;
  	fi[i] = po(f[i],mm-2);
  }
  LL an = 0;
  for(LL x = 0; x<=k; x++){
  	LL aa = po(m-1, n-1-x);
  	aa = (ncr(n-1,x)*aa)%mm;
  	an = (an + aa)%mm;
  }
  an = (an*m)%mm;
  cout<<an<<endl;
  return 0;
}