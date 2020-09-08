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
const int MAXN = 1e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// 2, 2 => 4
// 1 + 2


vector<LL> prime;
bool comp[MAXN];
LL f[MAXN];
LL ans[MAXN];
/*
	mu(p) = -1; 
	mu(p*p*..) = 0,
*/

// sigma(i*phi[i])
// 1, 2,...,p

void sieve(){
	fill(comp, comp + MAXN, 0);
	f[1] = 1;
	for(LL i = 2; i < MAXN; i++){
		if(!comp[i]){
			prime.pb(i);
			f[i] = i-1;
		}
		for(auto p:prime){
			if(p*i>MAXN) break;
			comp[p*i] = 1;
			if(i%p == 0){
				f[i*p] = p*f[i];
				break;
			}
			f[i*p] = f[i]*f[p];
		}
	}
	for(LL i = 1; i<MAXN; i++){
		for(LL j = i; j<MAXN; j += i)
		{
			ans[j] += f[i]*i;
		}
		ans[i] = ((ans[i]+1)/2)*i;
	}
}


int main(){
  fio();
  sieve();
  int t; cin>>t;
  while(t--){
  	LL n; cin>>n;
  	cout<<ans[n]<<endl;
  }
  return 0;
}