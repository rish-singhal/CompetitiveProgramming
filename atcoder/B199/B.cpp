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
const LL INF = 1e17;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin >> n;
  LL ans = 0;
  vector <LL> a(n);
  LL ma = 0;
  forn(i, n){
  	cin >> a[i];
  	ma = max(a[i], ma);
  }
  LL mi = INF;
  forn(i, n){
  	LL b; cin >> b;
  	mi = min(mi, b);
  }
  if(mi >= ma){
  	cout << mi - ma +1 << "\n";
  }
  else cout <<"0\n";
  return 0;
}