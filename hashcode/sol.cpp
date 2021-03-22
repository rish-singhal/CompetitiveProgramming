#include<bits/stdc++.h>
#include <random>
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
	std::random_device rd;
    std::mt19937 g(rd());
	LL d, n, s, c, f;
	cin >> d >> n >> s >> c >> f;
	map <pair<int,int>, string> name;
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

	vector <int> endcheck(n,0);
	vector <int> path[n];
	vector <int> pathlen;
	for(int i = 0; i < c; i++) {
		int p;
		cin >> p;
		pathlen.push_back(p);
		for(int j = 0; j < p; j++) {
			string sname; cin >> sname;
			if(!j) path[p].push_back(iname[sname].fi);
			path[p].push_back(iname[sname].se);
			endcheck[iname[sname].se]++;
		}
	}

	// removing redundent roads
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += endcheck[i]?0:1;

	// cout << sum << endl;
	
	// solution d

	int cnt2 = 0;
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(auto b: beg[i])
		{
			if(endcheck[i]) 
				cnt++;
		}
		if(cnt == 0)
			continue;
		cnt2 ++;
	}

	cout << cnt2 << endl;
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(auto b: beg[i])
		{
			if(endcheck[i]) 
				cnt++;
		}
		if(cnt == 0)
			continue;

		cout << i << "\n" << cnt << endl;

		std::list<int> l(sz(beg[i]));
    	std::iota(l.begin(), l.end(), 0);
 
    	std::vector<std::list<int>::iterator> v(l.size());
   		std::iota(v.begin(), v.end(), l.begin());
 
    	std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
		
		for(auto k: v)
		{
			if(endcheck[i]) cout << name[{beg[i][sz(beg[i]) - *k - 1], i}] << " " << 1 << endl;
		}
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