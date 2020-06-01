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
const int MAXN = 5e5 +5;
const LL m = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL f[MAXN], fi[MAXN];

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) an = (an*a)%m;
	return an;
}

LL ncr(LL a, LL b){
	if(a<b) return 0;

	LL an = (f[a]*fi[b])%m;
	return (an*fi[a-b])%m;
}

int main(){
  fio();
  f[0] = fi[0] = 1;
  for1(i,MAXN-1){
  	f[i] = (f[i-1]*i)%m;
  	fi[i] = po(f[i],m-2);
  }
  LL n,k; cin>>n>>k;
  if(k==1){
  	cout<<n<<endl;
  	return 0;
  }
  LL an =  0;
  for1(i,n){
  	LL c = ncr(((n/i)-1), k-1);
  	an = (an+c)%m;
  }
  cout<<an<<endl;
  return 0;
}