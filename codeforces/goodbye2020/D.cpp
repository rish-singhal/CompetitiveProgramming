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

int n ;
vector <LL> w(MAXN);
vector <int> adj[MAXN];

vector <LL> deg(MAXN);

void solve(){
	cin>>n;
	LL su = 0;
	LL ans = 0;
	forn(i,n)  deg[i] = 0;
	forn(i,n){
		cin >> w[i];
		ans += w[i];
		adj[i].clear();
	}

	forn(i,n - 1){
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
		deg[a]++; 
		deg[b]++;
	}
	vector <pair<LL, LL>> pa;
	forn(i,n)
		pa.pb({w[i], deg[i] - 1});

	sort(all(pa));
	reverse(all(pa));

	cout << ans << " ";
	int pp = 0;
	forn(i, n - 2)
		{
			while(pa[pp].se == 0) pp++;
			ans += pa[pp].fi;
			pa[pp].se --;	
			cout << ans << " ";
		}
	cout << endl;	
}

int main(){
  fio();	
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
