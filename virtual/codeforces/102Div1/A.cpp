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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// 3*(a+1) = 3*a + 3 >= 2*a 1+ 4
// 2*a + 4

LL calc(LL a, LL b, LL c){
	return (a+1)*(b+2)*(c+2);
}

int main(){
  fio();
  LL n;
  cin >> n;
  LL ma = 0;
  LL mi = LLONG_MAX;
  for(LL a = 1; a*a*a <= n; a++){
  	if(n%a != 0) continue;
  	for(LL b = 1; b*b <= (n/a); b++){
  		if(n%b != 0) continue;
  		if(n%(a*b) != 0) continue;
  		LL c = (n/(a*b));
  		ma = max({ma, calc(a, b, c), calc(c, b, a), calc(b, c, a)});
  		mi = min({mi, calc(a, b, c), calc(c, b, a), calc(b, c, a)});
  	}
  }
  cout << mi - n<< " " << ma - n << "\n";
  return 0;
}