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
const LL mm = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL k;

map <pair<LL,LL>, LL> an;

LL dp(LL w, LL b){
	cout << w << " " << b << endl;
	LL n = w + b;
	if(w < 0 || b < 0) {
		return 0;
	}
	if(w > b + k) {
		return 0;
	}
	if(n == 1 || w == 0 || b == 0) {
		if(w <= b + k){
			return 1;
		}
	}
	if(an.find({w, b}) != an.end()) {
		return an[{w,b}];
	}
	LL ann = an[{w, b}] = (dp(w - 1, b) + dp(w, b - 1)) % mm;
	return ann;
}

int main(){
  fio();
  LL w, b; cin >> w >> b >> k;
  if(w > b + k) {
  	cout << 0 << endl;
  	return 0;
  }
  cout << dp(w, b) << endl;
  return 0;
}