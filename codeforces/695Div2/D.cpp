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
const int MAXN = 5e3 +5;
const LL mm = 1e9 + 7;
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][MAXN];

int main(){
  fio();	
  LL n, k, q; cin >> n >> k >> q;
  vector <LL> v(n);
  forn(i, n) cin >> v[i];
  dp[0][0] = dp[n-1][0] = 1;
  for(int i = 1; i < n - 1; i ++)
  	dp[i][0] = 1;

  for(int i = 1; i <= k; i++)
  {
  		for(int j = 0; j < n; j++)
  		{			
  			dp[j][i] = 0;
  			for(auto z: {-1, 1})
  				if(j + z >= 0 && j + z < n)
  					dp[j][i] = (dp[j][i] + dp[j + z][i - 1])%mm;

  		}
  }

  vector <LL> an(n, 0);

  for(int i = 0; i < n; i++)
  	for(int j = 0; j <= k; j++)
  		an[i] = (an[i] + (dp[i][j]*dp[i][k-j])%mm)%mm;

  LL sum = 0;
  for(int i = 0; i < n; i++)
  {
  	sum = (sum + v[i]*an[i])%mm;
  }
  while(q--){
  	LL a, x; cin >> a >> x;
  	a --;
  	sum = (sum - v[a]*an[a])%mm;
  	sum = (mm + sum)%mm;
  	sum = (sum + x*an[a])%mm;
  	v[a] = x;
  	cout << sum << endl;
  }
  return 0;
}
