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
const LL INF = 1e18 + 1;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  LL n, q; cin >> n >> q;
  vector <LL> v(n + 1);
  v[0] = 0;
  forn(i, n){
  	cin >> v[i + 1];
  }
  vector<LL> vv(n);
  forn(i, n){
  	vv[i] = v[i + 1] - v[i] - 1;
  }
  for1(i, n - 1) {
  	if(vv[i] >= INF - vv[i - 1] || vv[i - 1] == INF)
  		vv[i] = INF;
  	else 
  		vv[i] += vv[i-1];
  }
  // forn(i, n) {
  // 	cout << vv[i] << " ";
  // }
  // cout << endl;
  while(q--){
  	LL k; cin >> k;
  	int x = lower_bound(all(vv), k) - vv.begin();
  	//cout << x << endl;
  	if(k >= v[n]){
  		cout << (k + n) << endl;
  	}
  	else
  		cout << (v[x] + k - (x>=1?vv[x - 1]:0)) << endl;
  }
  return 0;
}