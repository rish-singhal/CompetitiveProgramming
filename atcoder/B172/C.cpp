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
const int MAXN = 1e7 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


vector<LL> prime;
bool comp[MAXN];
LL f[MAXN], cnt[MAXN];

/*
	mu(p) = -1; 
	mu(p*p*..) = 0,
*/

void sieve(){
	fill(comp, comp + MAXN, 0);
	f[1] = 1;
	for(LL i = 2; i < MAXN; i++){
		if(!comp[i]){
			prime.pb(i);
			f[i] = 2;
			cnt[i] = 2;
		}
		for(auto p:prime){
			if(p*i>MAXN) break;
			comp[p*i] = 1;
			if(i%p == 0){
				f[i*p] = f[i] / cnt[i] * (cnt[i] + 1);
				cnt[i * p] = cnt[i] + 1;
				break;
			}
			f[i*p] = f[i]*f[p];
			cnt[i * p] = 2;
		}
	}
}



int main(){
  fio();
  sieve();
  LL n; cin>>n;
  LL an = 0;
  for1(i,n){
  	an+=i*f[i];
  }
  cout<<an<<endl;
  return 0;
}