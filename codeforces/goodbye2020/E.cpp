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
const int MAXN = 5e5 +5;
// check MAXN
const LL m = 1e9 + 7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve(){
	LL n; cin>>n;
	vector <LL> v(n);
	forn(i,n) cin >> v[i];
	vector <LL> cal(60);
	forn(i,n){
		for(LL p = 0; p < 60; p++)
			if((v[i]>>p)&1) cal[p]++;
	}
	vector <LL> f(n);
	forn(i,n){
		f[i] = 0;
		LL mu = 1;
		for(LL p = 0; p < 60; p++)
		{
			if((v[i]>>p)&1)
			{
				LL kk = (n * mu) % m;
				f[i] = (f[i] + kk) % m;
			}
			else
			{
				LL kk = (cal[p] * mu) % m;
				f[i] = (f[i] + kk) % m;
			}
			mu = (mu * 2) % m;
		}
	}
	LL ans = 0;
	forn(i,n){
		LL su = 0;
		LL mu = 1;
		for(LL p = 0; p < 60; p++)
		{
			if((v[i]>>p)&1)
			{
				LL kk = (cal[p] * mu) % m;
				su = (su + kk) % m;
			}
			mu = (mu * 2) % m;
		}
		ans = (ans + (su * f[i]) % m) % m;
	}
	cout << ans << endl;
}

int main(){
  fio();	
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
