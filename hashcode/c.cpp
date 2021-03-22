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

void solve() {
	LL d, n, s, c, f;
	cin >> d >> n >> s >> c >> f;
	map <pair<int,int>, string> name;
	map <string,int> traffic;
	map <string, pair<int,int>> iname;
	map <pair<int,int>, LL> len;
	vector<int> beg[n];
	vector<int> end[n];
	
	for(int i = 0; i < s; i++)	{
		int b, e; cin >> b >> e;
		cin >> name[{b,e}];
		cin >> len[{b,e}];
		iname[name[{b,e}]] = {b,e};
		beg[e].push_back(b);
		end[b].push_back(e);
	}

	vector <int> path[n];
	vector <int> pathlen;
	for(int i = 0; i < c; i++) {
		int p;
		cin >> p;
		pathlen.push_back(p);
		for(int j = 0; j < p; j++) {
			string sname; cin >> sname;
			traffic[sname]++;
			if(!j) path[p].push_back(iname[sname].fi);
			path[p].push_back(iname[sname].se);
		}
	}

	// solution d
	cout << n << endl;
	for(int i = 0; i < n; i++) {
		cout << i << "\n";
		vector<pair<int,string>> maxTraffic;
		for(auto b: beg[i])
			maxTraffic.push_back(make_pair(traffic[name[{b, i}]],name[{b, i}]));
		sort(maxTraffic.begin(), maxTraffic.end());
		cout<<min((size_t)1000,maxTraffic.size())<<"\n";
		for(int i1=0;i1<min((size_t)1000,maxTraffic.size());i1++)
			cout<<maxTraffic[maxTraffic.size()-1-i1].second<<" 1\n";
	}


	// solution a
	// cout << "3\n0\n1\nrue-de-londres 1\n1\n2\n";
	// cout << "rue-d-athenes 1\nrue-d-amsterdam 1\n2\n1\n";
	// cout << "rue-de-moscou 1\n";
}

int main(){
  fio();
  solve();
  return 0;
}