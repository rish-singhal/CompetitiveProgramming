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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool inv){
	int n = a.size();
	if(n==1) return;
	vector<cd> ev(n/2), od(n/2);
	for(int i = 0; i < n ; i+=2)
		ev[i/2] = a[i], od[i/2] = a[i+1];
	fft(ev, inv), fft(od, inv);
	double ang = 2 * PI / n * (inv?1:-1);
	cd w(1), wn(cos(ang), sin(ang));
	for(int i = 0; 2*i < n; i++){
		a[i] = ev[i] + w*od[i];
		a[i + n/2] = ev[i] - w*od[i];
		if(inv) a[i] /= 2, a[i+n/2] /=2;
		w *= wn;
	}
}

vector<int> multiply(vector<int> const& a, vector<int> const& b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	int sz = a.size() + b.size();
	while(n < sz) n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, 0), fft(fb, 0);
	forn(i,n) fa[i] *= fb[i];
	fft(fa, 1);
	vector<int> res(sz-1);
	forn(i,sz-1) res[i] = round(fa[i].real());
	return res;
}

ostream& operator << (ostream &output, vector<int> const &a){
	for(auto i:a) output<<i<<" ";
	return output;
}

int main(){
  fio();
  int n,m; cin>>n>>m;
   vector<int> a(n), b(m);
   forn(i,n) cin>>a[i];
   forn(i,m) cin>>b[i];
   auto res = multiply(a,b);
   cout<<res<<endl;
   return 0;
}