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
const LL m = 998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) return an*a%m;
	return an;
}

LL f[105];
LL fi[105];

LL calc(LL a){
	LL an = 1;
	LL su = 0;
	LL az = a;
	for(LL i=2;i*i<=az;i++){
		if(a%i==0){
			LL cnt = 0;
			while(a%i==0){
				a/=i;
				cnt++;
			}
			su+=cnt;
			an = (an*fi[cnt])%m;
		}
	}
	if(a){
		su++;
	}
	an = an*f[su]%m;
	return an;
}

int main(){
  fio();
  LL d; cin>>d;
  int cnt = 0;
  f[0]=fi[0]=1;
  for1(i,104){s
  	f[i] = (i*f[i-1])%m;
  	fi[i] = po(f[i],m-2);
  }
  LL q; cin>>q;
  while(q--){
  	LL a,b; cin>>a>>b;
  	LL g = __gcd(a,b);
  	a/=g;
  	b/=g;
  	cout<<(calc(a)*calc(b)%m)<<endl;
  }
  return 0;
}