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
const int N = 24;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n;  cin>>n;
  vector <LL> dp(1 << N, 0);
  forn(i,n){
  	string s; cin>>s;
  	int msk = 0;
  	for(auto c: s)
  		msk |= 1 << (c - 'a');
  	dp[msk]++;
  }

  forn(i,N)
  	forn(msk, 1<<N)
  		if(msk & (1 << i))
  			dp[msk] += dp[msk^(1<<i)];

  LL ans = 0;

  forn(i, 1<<N)
  	ans ^= (n - dp[i])*(n - dp[i]);

  cout << ans << endl;
  return 0;
}