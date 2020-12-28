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
// check MAXN

// b*m > a
// b/a > m

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<LL> a(n), b(n);
  	vector<pair<LL,LL>> v(n);
  	forn(i,n) cin>>a[i];
  	forn(i,n) cin>>b[i];
  	forn(i,n) v[i].fi = a[i], v[i].se = b[i];
  	sort(all(v));
  	for(int i = n - 2; i >= 0 ; i --){
  		v[i].se += v[i+1].se;
  	}
  	LL an = 1e18;
  	for(int  i = 0; i < n - 1; i++){
		if(i + 1 < n)an = min(max(v[i].fi, v[i+1].se), an);
  	}
  	an = min(v[n-1].fi, an);
  	an = min(an, v[0].se);
  	cout<<an<<endl;
  }
  return 0;
}