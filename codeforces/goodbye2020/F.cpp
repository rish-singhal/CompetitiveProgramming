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
const int MAXN = 5e5 +5;
const LL mm = 1e9 + 7;
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n)
{
	if(!n) return 1;
	LL an = po(a, n/2);
	an = (an * an) % mm;
	if(n&1) an = (an * a) % mm;
	return an;
}

void solve(){
	int n, m; cin >> n >> m;
	vector <pair<LL, pair<set<LL>, LL> >> vk;
	forn(i, n)
	{
		int k; cin >> k;
		set <LL> v;
		forn(j, k) {
			int u; cin>> u;
			v.insert(u);
		}
		vk.pb({k, {v, i + 1}});
	}
	//sort(all(vk));
	vector <LL> basis(m + 1, 0);
	vector <set<LL>> basisv(m + 1);
	forn(i, n){
		set <LL> s = vk[i].se.fi;
		vector <LL> vv;
		int tt = 0;
		while(s.size())
			{	//cout << j << " ";
				LL k = *s.begin();
				if(basis[k] == 0) {
					basis[k] = vk[i].se.se;
					basisv[k] = s;
					break;
				}

				vv.pb(k);
				for(auto o : basisv[k])
				{
					if(s.find(o) == s.end())
						s.insert(o);
					else 
						s.erase(o);
				}
			}
	}

	set <LL> ans;
	for1(i, m)
	{
		if(basis[i]) {
			ans.insert(basis[i]);
			// << basis[i] << endl;
		}
	}
	LL s = (LL)ans.size();
	cout << po(2, s) << " " << s << endl;
	//sort(all(ans));
	for(auto i : ans)
		cout << i << " ";
	cout << endl;
}

int main(){
  fio();	
  solve();
  return 0;
}
