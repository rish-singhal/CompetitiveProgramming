#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 + 5;


void solve(int t) {
  int n, k; cin >> n >> k;
  vector <LL> v(n);
  map <LL, LL> m;
  forn (i, n) {
    cin >> v[i];
    m[v[i]] = i;
  }
  int cc = 0;
  for (auto i: m) {
    v[i.se] = cc++;
  }
  // for (auto i: v) {
  //   cout << i << " ";
  // }
 // cout << endl;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] != v[i - 1] + 1) {
      cnt++;
    }
  }
  cnt++;
  cout << (cnt <= k? "YES" : "NO") << endl;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1; 
  cin >> T;
  cout << setprecision(10);
  forn(t, T) {
  	solve(t);
  }
  return 0;
}
