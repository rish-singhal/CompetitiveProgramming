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
	vector< pair<LL, LL> > ve;
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
			ve.pb({pp.size(), msk});
	}
	sort(all(ve));
	reverse(all(ve));
	set <LL> s;
	LL ans = 0;
	for(auto msk: ve)
	{
		int b = 0;
		vector <int> pp;
		forn(no, n)
			if(msk.se & (1LL << no)) {
				pp.pb(no);
				if(s.find(no) != s.end())
					{
						b = 1;
						break;
					}
			}

	    if(!b){
	    	for(auto c: pp)
	    		s.insert(c);
	    	ans ++; 
	    }
	}
	cout << ans - 1<< endl;
}

int main(){
  fio();	
  solve();
  return 0;
}
