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
  int n;
  cin >> n;
  vector <double> v(n);
  forn (i, n) {
    cin >> v[i];
  }
  sort(all(v));
  double ans = v[n - 1];
  double x = 0;
  forn (i, n - 1) {
    x += v[i];
  }
  x /= (n - 1);
  cout << ans + x << endl;
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
