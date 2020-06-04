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
const int MAXN = 5e2 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int dp[MAXN][MAXN];
int n; 

void chmin(int &a, int b){
	a = (a>b?b:a);
}

int dpx(int a, int b){
	if(a>b || a>=n || b<0) return 0;
	return dp[a][b];
}

int main(){
  fio();
  cin>>n;
  vector<int> a(n);
  forn(i,n) cin>>a[i];
  forn(i,n)forn(j,n) dp[i][j] = 1e8;
  for(int len = 1; len <= n; len++){
  	for(int l=0; l+len-1<n; l++){
  		int r = l + len - 1;
  		if(len==1){
  			dp[l][r] = 1;
  			continue;
  		}
  		chmin(dp[l][r], dpx(l+1,r)+1);
  		if(a[l]==a[r]){
  			chmin(dp[l][r], dp[l+1][r-1]);
  		}
  		if(a[l]==a[l+1])
  			chmin(dp[l][r], dpx(l+2,r)+1);
  		for(int x = l+1;x<=r;x++){
  			if(a[x]==a[l]) chmin(dp[l][r], dp[l+1][x-1]+dp[x+1][r]);
  		}
  	}
  }
  cout<<dp[0][n-1]<<endl;
  return 0;
}