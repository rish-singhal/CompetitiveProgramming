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

int main(){
  fio();
  int t; cin >> t;
  while(t--) {
  	int n; cin >> n;
  	vector <LL> v(n);
  	forn(i, n) {
  		cin >> v[i];
  	}
  	LL ans = 0;
  	auto check = [&](int l, int r) {
  		for(int i = l; i <= r; i++)
  			for(int j = i + 1; j <= r; j++)
  				for(int k = i + 1; k < j; k++)
  					if(min(v[i], v[j]) <= v[k] && v[k] <= max(v[i], v[j]))
  						return 0;
  		return 1;
  	};

  	for(int len = 1; len <= 4; len++) {
  		for(int i = 0; i + len - 1 < n; i++) {
  			ans += check(i, i + len - 1);
  		}
  	}

  	cout << ans << endl;
  }
  return 0;
}