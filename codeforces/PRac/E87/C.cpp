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
const int MAXN = 4e3 +5;
const LL mm = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL f[MAXN], fi[MAXN];

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an=(an*an)%mm;
	if(n&1) an = (an*a)%mm;
	return an;
}

LL ncr(LL a, LL b){
	if(b>a) return 0; 
	LL an = (f[a]*fi[a-b])%mm;
	return (an*fi[b])%mm;
}

int main(){
  fio();
  f[0] = fi[0] = 1;
  for1(i,MAXN-1){
  	f[i] = (i*f[i-1])%mm;
  	fi[i] = po(f[i], mm-2);
  }
  LL n,k; 
  cin>>n>>k;
  cout<<ncr(n+k-1,n-1)<<endl;

  return 0;
}