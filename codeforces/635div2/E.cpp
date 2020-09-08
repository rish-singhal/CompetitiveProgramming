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
const int MAXN = 3e3 +5;
const LL mm = 998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][MAXN], pdf[MAXN][MAXN];

int main(){
  fio();
  string a,b; cin>>a>>b;
  int n = a.size(), m = b.size();
  forn(i,n) dp[i][0] = 1;
  forn(i,n) pdf[i][0]+=(a[i]==b[0]?dp[i][0]:0);
  for(int l=1;l<=m;l++){
  	for(int i=0;i<n;i++){
  		dp[i][l] = pdf[i][l-1];
  	}
  	for(int i=0; i<n; i++){
  		pdf[i][l] = ((i>=1?pdf[i-1][l]:0)%mm + (a[i]!=b[m-l]?0:dp[i][l]))%mm; 
  	}
  }
  for1(i,m){
  	forn(j,n) cout<<dp[i][j]<<" ";
  	cout<<endl;
  }
  return 0;	
}