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
const LL mm = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin >> t;
  while (t--) {
  	int n; cin >> n;
  	int dp[32][n];
  	forn(i, 32) {
  		forn(j, n){
  			dp[i][j] = 0;
  		}
  	}
  	
  	forn (i, n) {
  		LL x; cin >> x;
  		forn (b, 32) {
  			if ((x >> b) & 1) {
  				dp[b][i]++;
  			}
  		}
  	}
  	vector<LL> dd(32);
  	forn(b, 32){
  		dd[b] += dp[b][0];
  	}
  	forn(b, 32) {
  		for1(i, n - 1) {
  			dp[b][i] ^= dp[b][i - 1];
  			dd[b] += dp[b][i];
  		}
  	}

  	LL an = 0;
  	forn(i, 32) {
  		an = (an + ((((dd[i])%mm)*(n + 1 - dd[i]))%mm * (1LL<<i)%mm)%mm) % mm;
  	}
  	cout << an << endl;
  }
  return 0;
}