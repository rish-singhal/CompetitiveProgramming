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
	int n; cin >> n;
	vector <int> v(n);
	forn(i, n) cin >> v[i];
	vector <vector<LL>> dp(n,vector<LL>(n, 0));
	sort(all(v));
	for(int len = 2; len <= n; len++){
		for(int l =0; l + len - 1 < n; l++){
			int r = l + len - 1;
			if(l + 1 < n)
				dp[l][r] = dp[l+1][r] + v[r] - v[l];
			if(r - 1 >= 0)
				dp[l][r] = min(dp[l][r], dp[l][r-1] + v[r] - v[l]);
		}
	}
	cout << dp[0][n-1] << endl;
}

int main(){
  fio();
  solve();
  return 0;
}