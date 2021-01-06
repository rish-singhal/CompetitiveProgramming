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

void solve(){
	int n, m; cin>>n>>m;
	int mat[n][n];
	forn(i,n) forn(j, n) mat[i][j] = (i==j);
	forn(i,m){
		int u, v; cin>>u>>v;
		u--, v--;
		mat[u][v] = mat[v][u] = 1;
	}
	vector <bool> isclique(1LL << n, false);
	forn(msk, 1LL << n)
	{
		vector <int> pp;
		forn(no, n)
			if(msk & (1LL << no)) pp.pb(no);
		int b = 0;
		for(auto i:pp)
			for(auto j:pp)
				if(!mat[i][j]) b = 1;
		if(!b)
			isclique[msk] = 1;
	}
  vector <LL> dp(1LL << n, 0);
  forn(msk, 1LL << n)
  {
    dp[msk] = 1e17;
    if(isclique[msk])
      dp[msk] = 1;
    else{
      for(LL smsk = msk; smsk; smsk = (smsk - 1)&msk)
        dp[msk] = min(dp[msk], dp[smsk] + dp[smsk^msk]);
    }
  }
  cout << dp[(1LL << n) - 1] << endl;
}

int main(){
  fio();	
  solve();
  return 0;
}
