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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL f[5];

LL ncr(LL a, LL b){
	LL an = 1;
	LL k = b;
	while(k){
		an*=a;
		a--, k--;
	}
	return an/f[b];
}

LL de(LL n){
	LL an = 0;
	for(int i = 2; i<=n; i++){
		an += (i%2==0?f[n]/f[i]:-1*f[n]/f[i]);
	}
	return an;
}

int main(){
  fio();
  int n,k; cin>>n>>k;

  f[0]=1;
  for1(i,5) f[i]=i*f[i-1];
  LL an = 1;
  int t = 0;
  for(int i=2;i<=k;i++){
  	an+=ncr(n,i)*de(i);
  }
  cout<<an<<endl;
  return 0;
}