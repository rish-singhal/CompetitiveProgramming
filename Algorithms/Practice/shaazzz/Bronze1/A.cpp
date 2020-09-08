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
const int MAXN = 1e3 +5;
const LL mod = 1e9 + 7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%mod;
	if(n&1) return (an*a)%mod;
	return an;
}


LL f[MAXN], fi[MAXN];

int main(){
  fio();
  f[0] = fi[0] = 1;
  for1(i,MAXN-1){
  	f[i] = i*f[i-1]%mod;
  	fi[i] = po(f[i], mod-2);
  } 
  LL k; cin>>k;
  LL n = 0;
  LL an = 1;
  while(k--){
  	LL x; cin>>x;
  	n+=x-1;
  	an = (an*fi[x-1])%mod;
  }
  an = (an*f[n])%mod;
  cout<<an<<endl;
  return 0;
}