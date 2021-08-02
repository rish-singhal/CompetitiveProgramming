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
const int MAXN = 1e5 +5;

struct Tree {
  typedef LL T;
  static constexpr T unit = 0;
  T f(T a, T b) { return gcd(a, b); } // (any associative fn)
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

void solve(int t) {
  int n; cin >> n;
  vector <LL> v(n);
  forn (i, n) {
    cin >> v[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  vector <LL> vv(n-1);
  forn(i, n - 1) {
    vv[i] = abs(v[i] - v[i + 1]);
  }
  Tree tr(n - 1);
  forn(i, n - 1) {
    tr.update(i, vv[i]);
  }
  int r = 0;
  int ans = 0;
  for (int l = 0; l < n - 1; l++) {
    if (r < l) r = l;
   // cout << "l, r: " << l << ", " << r << " " << tr.query(l, r + 1) << endl;
    while(r < (n - 1) && tr.query(l, r + 1) != 1) {
      r++;
    }
   // cout << "l, r: " << l << ", " << r << endl;
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1; 
  cin >> T;
  forn(t, T) {
  	solve(t);
  }
  return 0;
}
