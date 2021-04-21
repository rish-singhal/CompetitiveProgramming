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

int main(){
  fio();
  int n, q;
  cin >> n >> q;
  vector <vector<int>> a(n);
  vector<int> v(n);
  forn(i, n){
  	int x;
  	cin >> x;
  	v[i] = x - 1;
  	a[x-1].push_back(i+1);
  }

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  while(q--){
  	int l, r;
  	cin >> l >> r;
  	int ans = 1;
  	int m = r - l + 1;
  	forn(_, 40){
  		int ind = uniform_int_distribution<int>(l,r)(rng);
  		int num = v[ind - 1];
  		int f = upper_bound(all(a[num]), r) - lower_bound(all(a[num]), l);
  		ans = max(ans, 2*f - m);
  	}
  	cout << ans << endl;
  }
  return 0;
}