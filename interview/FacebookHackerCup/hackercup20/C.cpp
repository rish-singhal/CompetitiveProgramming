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

void solve(){
	int n; cin>>n;
	vector<pair<LL,LL>> v(n);
	// vector<pair<LL,LL>> vr(n);
	forn(i,n) cin>>v[i].fi>>v[i].se;
	sort(all(v));
	LL an  = 0;
	map <LL, LL> lan, ran;
	for(int i = 0; i < n; ++i) {
		auto &x = lan[v[i].fi + v[i].se];
		x = max(x, lan[v[i].fi] + v[i].se);
		an = max(x, an);
	}
	for(int i = n - 1; i >= 0; --i) {
		auto &x = ran[v[i].fi - v[i].se];
		x = max(x, ran[v[i].fi] + v[i].se);
		an = max(an, x);
	}
	for(auto i: lan){
		an = max(an, i.se + ran[i.fi]);
	}
	cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t) {
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}