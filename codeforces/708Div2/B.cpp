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
  fio();
  int t; cin >> t;
  while(t--){
  	 int n, m; cin >> n >> m;
  	 vector <int> v(m);
  	 forn(i, n){
  	 	int k; cin >> k;
  	 	v[k%m]++;
  	 }
  	 LL ans = 0;
  	 for(int i = 0; i + i <= m; i++){
  	 	if(i + i == m && v[i]){
  	 		ans ++;
  	 		continue;
  	 	}
  	 	if(i == 0 && v[i]){
  	 		ans ++;
  	 		continue;
  	 	}
  	 	if( i == 0 || i + i ==m)
  	 		continue;
  	 	LL k = min(v[i], v[m - i]);
  	 	LL p = max(v[i], v[m - i]);
  	 	LL z = p - k;
  	 
  	 	
  	 	if(k == 0){
  	 		ans += p;
  	 	}
  	 	else if(k > 0){
  	 		ans ++;
  	 		ans += (z >= 1?z - 1:0);
  	 	}
  	 }
  	 cout << (ans) << endl;
  }
  return 0;
}