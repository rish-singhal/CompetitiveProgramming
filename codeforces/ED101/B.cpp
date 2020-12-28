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


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--)
  {
  	int n; cin>>n;
  	vector <LL> a(n);
  	forn(i,n) cin>>a[i];
  	int m; cin>>m;
  	vector<LL> b(m);
  	forn(i,m) cin>>b[i];
  	LL val1 = 0, val2 = 0;
  	LL m1 = 0, m2 = 0;
  	forn(i,n) {
  		val1 += a[i];
  		m1 = max(m1, val1);
  	}

  	forn(i,m) {
  		val2 += b[i];
  		m2 = max(m2, val2);
  	}

  	cout << max(0LL, m1 + m2) << endl;
  }

  return 0;
}
