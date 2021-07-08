#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

LL k;

LL invxor(LL a, LL b) {
	vector <LL> va, vb;
	cout << a << " " << b << " " << k << " : ";
	while(a) {
		va.pb(a%k);
		a /= k;
	}
	while(b) {
		vb.pb(b%k);
		b /= k;
	}
	cout << sz(va) << " " << sz(vb) << " : ";
	int na = 0, nb = 0;
	LL ans = 0;
	LL kk = 1;
	while(na < sz(va) || nb < sz(vb)) {
		if(na < sz(va) && nb < sz(vb)) {
			ans += kk * ((va[na] - vb[nb] + k) % k);
			na++; nb++;
		}
		else if(na < sz(va)) {
			ans += kk * ((va[na]) % k);
			na++;
		}
		else if(nb < sz(vb)){
			ans += kk * ((vb[nb]) % k);
			nb++;
		}
		kk *= k;
	}
	cout << ans << "\n";
	return ans;
}

int main(){
  //fio();
  int t; cin >> t;
  while(t --) {
  	LL n; cin >> n >> k;
  	LL su = 0;
  	for(LL i = 0; i < n; i++) {
  		if(i >= 1) printf("%lld\n", invxor(i - 1, (i)));
  		else printf("%lld\n", i);
  		fflush(stdout);
  		int r;
  		cin >> r;
  		if(r == -1) {
  			return 0;
  		}
  		if(r == 1) {
  			break;
  		}
  	}
  }
  return 0;
}