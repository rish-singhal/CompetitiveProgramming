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

void solve() {
	LL n, c; cin >> n >> c;
	LL u = ((2 + n)*(n - 2 + 1))/2;
	if(c > u || c < n - 1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	//cout << "P" << endl;
	vector <LL> v(n - 1, 1);
	LL ns = c - (n - 1);
	for(int  i = 0; i < n - 1; i++)
	{
		if(ns >= (i+1)) {
			ns -= i + 1;
			v[i] += i + 1;
		}
		else {
			v[i] += ns;
			break;
		}
	}

	// for(auto i : v)
	// 	cout << i << " ";
	// cout << endl;


	vector <LL> an(n);
	for(int i = 0; i < n; i++)
		an[i] = i + 1;
	int cc = 0;
	for(int i = n - 2; i >= 0; i--) {
		int j = i + v[cc] - 1;
		vector <LL> nan = an;
		for(int k = i; k <= j; k++)
			nan[k] = an[j - k + i];
		an = nan;
		cc++;
	}
	for(auto i : an)
		cout << i << " ";
	cout << endl;
}

int main(){
  fio();
  int t; cin >> t;
  for1(i, t) {
  	cout << "Case #" << i <<": ";
  	solve();
  }
  return 0;
}