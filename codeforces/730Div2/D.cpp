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

// void fio(){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
// }

int main(){
  //fio();
  int t; cin >> t;
  while(t --) {
  	LL n, k; cin >> n >> k;
  	LL su = 0;
  	for(LL i = 0; i < n; i++) {
  		if(i >= 1) printf("%lld\n", i^(i-1));
  		else printf("%lld\n", i);
  		fflush(stdout);
  		int r;
  		cin >> r;
  		if(r == -1) {
  			return 0;
  		}
  		if(r == 1) {
  			break;
  		}
  	}
  }
  return 0;
}