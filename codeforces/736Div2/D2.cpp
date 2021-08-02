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

template<class T>
struct RMQ {
  vector <vector<T>> jmp;
  // any function f(a, f(b, c)) = f(a, b, c)
  T f(T a, T b) { return gcd(a, b); }
  // Initialize jmp with vector V
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - 2 * pw + 1);
      forn(j, sz(jmp[k]))
        jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }

  T query(int a, int b) {
    // returns f [a, b)
    int dep = 31 - __builtin_clz(b - a);
    return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);
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
  RMQ<LL> rmq(vv);
  int r = 0;
  int ans = 0;
  for (int l = 0; l < n - 1; l++) {
    if (r < l) r = l;
    while(r < (n - 1) && rmq.query(l, r + 1) != 1) {
      r++;
    }
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
