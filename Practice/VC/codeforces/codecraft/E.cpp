#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*
	p  = 7
	each player => 7 choices''
	k members...
	dp[N][MASK][K] .. 1e5 * 128 *  ==> 1.28 * 1e7 * 7
*/

LL n,p,k;
vector<LL> a(MAXN);
vector<vector<LL>> v(MAXN, vector<LL>(7));


int main(){
  fio();
  cin>>n>>p>>k;
  forn(i,n){
  	cin>>a[i];
  }
  forn(i,n){
  	forn(j,p) cin>>v[i][j];
  }
  
  return 0;
}