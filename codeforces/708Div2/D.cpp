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
	vector<LL> tag(n), s(n);
	forn(i,n) cin >> tag[i];
	forn(i,n) cin >> s[i];
	vector<LL> dp(n, 0);

	for(int j = 1; j < n; j++)
	{
		for(int i = j - 1; i >= 0; i--){
			if(tag[i] == tag[j]) continue;
			LL dpi = dp[i], dpj = dp[j], p = abs(s[i] - s[j]);
			dp[i] = max(dp[i], dpj + p);
			dp[j] = max(dp[j], dpi + p);
		}
	}
	cout << *max_element(all(dp)) << endl;
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	solve();
  }
  return 0;
}