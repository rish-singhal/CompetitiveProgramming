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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL gcd(LL a, LL b) {
	return a?gcd(b%a, a):b;
}

struct frac{
	LL a, b, dis;
	frac(LL a, LL b, LL dis): a(a), b(b), dis(dis){
		LL g = gcd(a, b);
		a = a/g;
		b = b/g;
	}
	bool operator <=(const frac& x){
		return a * x.b <= b * x.a;
	}
	bool operator >=(const frac& x){
		return a * x.b >= b * x.a;
	}
	bool operator ==(const frac& x){
		return a * x.b == b * x.a;
	}
	frac operator +(const frac& x){
		return frac(a + x.a, b + x.b, dis + x.dis);
	}
};

LL calc(const vector<LL>& v){
	frac prevfrac(0, 1, 0);
	LL ans = 0;
	for(int i = 0; i < sz(v) - 1; i++){
		frac newfrac(v[i+1] - v[i], 1, 1);
		if(newfrac >= prevfrac) {
			prevfrac = prevfrac + newfrac;
		}
		else{
			prevfrac = {0, 1, 0};
		}
		ans = max(ans, prevfrac.dis);
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector <LL> v(n);
	forn(i, n){
		cin >> v[i];
	}
	LL ans = calc(v);
	reverse(all(v));
	ans = max(ans, calc(v));
	cout << ans << endl;
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	solve();
  }
  return 0;
}