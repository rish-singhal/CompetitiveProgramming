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


void solve(int t) {
  int n, m; cin >> n >> m;
  multiset <int> s[n + 1];
  forn (i, m) {
    int u, v; cin >> u >> v;
    s[u].insert(v);
    s[v].insert(u);
  }
  int ans = 0;
  for1(i, n) {
    if((s[i].size() == 0) || (*(s[i].rbegin())) < i) {
      ans ++;
    }
  }
  int q; cin >> q;
  while (q--) {
    int in; cin >> in;
    if (in == 3) {
      cout << ans << endl;
    }
    else if (in == 2) {
      int u, v; cin >> u >> v;
      
      int k = ((*(s[u].rbegin())) < u);
      s[u].erase(s[u].find(v));
      int k2 = 1;
      if(s[u].size() > 0) {
        k2 = ((*(s[u].rbegin())) < u);
      }
      ans += k2 - k;

      k = ((*(s[v].rbegin())) < v);
      s[v].erase(s[v].find(u));
      k2 = 1;
      if(s[v].size() > 0) {
        k2 = ((*(s[v].rbegin())) < v);
      }

      ans += k2 - k;
    } else if(in == 1) {
      int u, v; cin >> u >> v;
      int k = 1;
      if(s[u].size() > 0) {
        k = ((*(s[u].rbegin())) < u);
      }
      s[u].insert(v);
      int k2 = ((*(s[u].rbegin())) < u);
      ans += k2 - k;
      
      k = 1;
      if(s[v].size() > 0) {
        k = ((*(s[v].rbegin())) < v);
      }
      s[v].insert(u);
      k2 = ((*(s[v].rbegin())) < v);

      ans += k2 - k;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1; 
  // cin >> T;
  forn(t, T) {
  	solve(t);
  }
  return 0;
}
