#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 + 5;

/**
 * Author: Simon Lindholm
 * Date: 2015-09-12
 * License: CC0
 * Source: me
 * Description: When you need to dynamically allocate many objects and don't care about freeing them.
 * "new X" otherwise has an overhead of something like 0.05us + 16 bytes per allocation.
 * Status: tested
 */

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
  static size_t i = sizeof buf;
  assert(s < i);
  return (void*)&buf[i -= s];
}
void operator delete(void*) {}

/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */

const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi;
  pair <int,int> mset = {inf, -1};
  pair <int, int> val = {0, -1};
  Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
  Node(vector<pair<int,int>>& v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo)/2;
      l = new Node(v, lo, mid); r = new Node(v, mid, hi);
      val = max(l->val, r->val);
    }
    else val = v[lo];
  }

  pair<int, int> query(int L, int R) {
    if (R <= lo || hi <= L) return {0, -1};
    if (L <= lo && hi <= R) return val;
    push();
    return max(l->query(L, R), r->query(L, R));
  }

  void set(int L, int R, pair<int,int> x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) mset = val = x;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = max(l->val, r->val);
    }
  }

  void push() {
    if (!l) {
      int mid = lo + (hi - lo)/2;
      l = new Node(lo, mid); r = new Node(mid, hi);
    }
    if (mset.fi != inf)
      l->set(lo,hi,mset), r->set(lo,hi,mset), mset = {inf, -1};
  }
};

void solve(int t) {
  LL n, m;
  cin >> n >> m;
  Node seg(0, inf + 1);
  vector <pair<int, pair <int, int>>> s;
  forn (i, m) {
    int u, v, x;
    cin >> u >> v >> x;
    u --;
    s.push_back({u, {v, x}});
  }
  sort(all(s));
  int in = 0;
  vector <LL> dp(n);
  vector <LL> par(n);
  forn (i, n) {
    pair <int, int> ma = {0, -1};
    int previn = in;
    while (in < m && s[in].fi == i) {
      pair <int, int> vv = seg.query(s[in].se.fi, s[in].se.se + 1);
      if (ma < vv) {
        ma = vv;
      }
      in ++;
    }
    par[i] = ma.se;
    dp[i] = ma.fi + 1;
    while (previn < m && s[previn].fi == i) {
     // cout << s[previn].se.fi << " "<<s[previn].se.se << " "<< i << " -- " << endl;
      seg.set(s[previn].se.fi, s[previn].se.se + 1, {dp[i], i});
      previn ++;
    }
  }

  // seg.set(7, 8, {1, 1});
  // cout << " outtt " << seg.query(7, 8).fi << endl;

  int ma = 0;
  int maxin = 0;
  forn (i, n) {
    if (dp[i] > ma) {
      ma = dp[i];
      maxin = i;
    }
  }

  // for (auto i : par) {
  //   cout << i << " ";
  // } 
  // cout << endl;

  // for (auto i : par) {
  //   cout << i << " ";
  // } 
  // cout << endl;

  set <int> ss;
  forn (i, n) ss.insert(i);
  ss.erase(maxin);
  while (par[maxin] != -1) {
    maxin = par[maxin];
    ss.erase(maxin);
  }

  cout << ss.size() << endl;
  for (auto i: ss) {
    cout << i + 1 << " ";
  }
  cout << endl;
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
