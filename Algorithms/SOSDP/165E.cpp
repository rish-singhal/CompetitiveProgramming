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
const int BITS = 22;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin>>n;
  vector <LL> v(n);
  forn(i,n) cin>>v[i];
  vector <LL> dp(1<<BITS, -1);
  forn(i,n)
  	dp[v[i]] = v[i];

  forn(i, BITS)
  	forn(mask, 1<<BITS)
  		if(mask & (1<<i))
  			dp[mask] = max(dp[mask], dp[mask^(1<<i)]);

  forn(i, n)
  	cout << dp[((1<<BITS) - 1)^v[i]] << " ";

  cout << endl;
  return 0;
}