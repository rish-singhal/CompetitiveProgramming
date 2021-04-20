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

int main(){
  //fio();
  int t; cin >> t;
  while(t--) {
  	int x, y; cin >> x >> y;
  	int n = 1;
  	while(n*n < x + y) n++;
  	if(y&1 || n*n != x + y || x < n || y < 2*(n-1)){
  		cout << "NO" << "\n";
  		continue;
  	}

  	y >>= 1;
  	vector <int> v(2);
  	int b = 0;
  	for(int f = 1; f <= n; f++) {
		int o = f, e = n - f;
		if(o*e == y){
			v[0] = o, v[1] = e;
			b = 1;
			break;
		}
  	}
  	if(!b){
  		cout << "NO" << "\n";
  		continue;
  	}
  	sort(all(v));
  	cout << "YES" << "\n";
  	cout << v[0] + v[1] << "\n";
  	for1(i, v[0]) {
  		cout << 1 << " " << i + 1 << "\n";
  	}
    for1(i, v[1] - 1){
    	cout << 2 << " " << v[0] + 1 + i << "\n";
    }
  }
  return 0;
}