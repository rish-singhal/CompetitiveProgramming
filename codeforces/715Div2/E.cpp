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
  LL dp[36];
  dp[0] = dp[1] = 1;
  for(LL i = 2; i < 36; i++){
  	int k = i - 1;
  	LL su = 0;
  	for(int j = 0; j <= k; j++){
  		if(1e18 - dp[j]*dp[k - j] <= su){
  			cout << i << endl;
  			break;
  		}
  		su += dp[j]*dp[k - j];
  	}
  	dp[i] = su;
  }
  int t; cin >> t;
  while(t--){
  	LL n, k; cin >> n >> k;
  	if(n < 36 && dp[n] < k){
  		cout << -1 << endl;
  		continue;
  	}
  	vector <int> v(n);
  	forn(i, n) v[i] = i+1;
  	if(k == 1){
  		forn(i, n) cout << (i+1) << " ";
  		cout << endl; 
  		continue;
  	}
  	if(k == 2){
  		swap(v[n-1], v[n]);
  		for(auto i:v) cout << i << " ";
  		cout << endl;
  		continue;
  	}
  	int su = k;
    while(su){
    	int z = 35;
    	for(int i = 0; i < 35; i++){
    		if(v[i] < k && v[i+1] >= k){
    			z = i + 1;
    		}
    	}
    	z--;
    	LL ind = 0;
    	LL kk = 0;
    	while(ind <= z && su <= kk + dp[ind]*dp[z-ind]){
    		kk += dp[ind]*dp[z-ind];
    		ind++;
    	}
    }
  }
  return 0;
}