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

void solve(){
	int n; cin >> n;
	vector <int> v(n);
	LL sum = 0;
	forn(i, n) {
		cin >> v[i];
		sum += (LL) v[i];
	}
	sort(all(v));
	bool check = true;
	for(int i = 1; i <= n; i++)
		check &= v[i-1] <= i;
	if(!check)
	{
		cout << "Second" << endl;
		return;
	}
	sum = ((LL)n*(n+1) - 2*sum)/2;
	if(sum&1)
		cout << "First" << endl;
	else 
		cout << "Second" << endl;
	return;
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	solve();
  }
  return 0;
}
