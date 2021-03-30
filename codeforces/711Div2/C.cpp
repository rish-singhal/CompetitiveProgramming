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

LL dpf[1005][1005], dpb[1005][1005];

LL solvef(LL n, LL k){
	LL &ans = dpf[n][k];
	if(ans != -1) 
		return ans; 
	
	return ans;
}


LL solveb(LL n, LL k){
	LL &ans = dpb[n][k];
	if(ans != -1) 
		return ans; 
	
	return ans;
}

int main(){
  fio();
  forn(i, 1005)
   forn(j, 1005)
   	dpf[i][j] = dpb[i][j] = -1;

  forn(i, 1005){
  	dpf[1][i] = 1;
  	if(i > 1) dpb[1][i] = 1;
  } 	

  forn(i, 1005){
  	dpf[i][1] = 1;
  	dpb[i][1] = 0;
  } 	

  int t; cin >> t;
  while(t--){
  	int n, k; cin >> n >> k;
  	cout << solvef(n, k) + solveb(n, k) << endl;
  }
  return 0;
}