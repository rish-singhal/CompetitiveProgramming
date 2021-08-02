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
  int n; cin >> n;
  string e; cin >> e;
  string g; cin >> g;
  int cnt = 0;
  forn (i, n) {
    if (e[i] == '0') {
      if (g[i] == '1') {
        cnt ++;
      } else {
        continue;
      }
    } else {
      if (g[i] == '0') {
        continue;
      } else {
        if (i >= 1 && e[i - 1] == '1') {
            cnt ++;
            e[i - 1] = '2';
        } else if (i + 1 < n && e[i + 1] == '1') {
            cnt ++;
            e[i + 1] = '2';
        }
      }
    }
  }
  cout << cnt << endl;
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
