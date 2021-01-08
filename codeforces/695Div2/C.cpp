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
const int MAXN = 5e5 +5;
const LL mm = 1e9 + 7;
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();	
  int a, b, c; cin >> a >> b >> c;
  vector <LL> aa(a), bb(b), cc(c);
  
  LL ma = 1e17, mb = 1e17, mc = 1e17;
  LL sum = 0;
  LL suma = 0, sumb = 0, sumc = 0;
  forn(i, a) {
  	cin >> aa[i];
  	ma = min(ma, aa[i]);
  	sum += aa[i];
  	suma += aa[i];
  }
  forn(i, b) {
  	cin >> bb[i];
  	mb = min(mb, bb[i]);
  	sum += bb[i];
  	sumb += bb[i];
  }
  forn(i, c) {
  	cin >> cc[i];
  	mc = min(mc, cc[i]);
  	sum += cc[i];
  	sumc += cc[i];
  }
  vector <LL> vv = {ma, mb, mc};

  vector <LL> sus = {suma, sumb, sumc};

  for(int i = 0; i < 3; i ++)
  	for(int j = i + 1; j < 3; j++)
  		sus.push_back(vv[i] + vv[j]);
  
  sort(all(sus));

  // for(auto x : sus)
  // 	cout << x << endl;
  cout << (sum - 2*(sus[0])) << endl;
  

  return 0;
}
