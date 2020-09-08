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
const LL m = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  string s,t; cin>>s>>t;
  int k = t.size();
  while(t.size()!=s.size())
  	t+='.';
  int n = s.size();
  LL dp[n+1][n+1];
  forn(i,n) forn(j,n) dp[i][j]  = 0;
  forn(i,n)
  	dp[i][i] = s[0]==t[i] || t[i]=='.'?2:0;
  for1(i,n-1){
  	int len = i;
  	for(int j=0; j+len-1<n;j++){
  		int l = j, r = j+len-1;
  		if(l-1>=0 && (t[l-1]==s[i] || t[l-1]=='.'))
  			dp[l-1][r] = (dp[l-1][r] + dp[l][r])%m;
  		if(r+1<n && (t[r+1]==s[i] || t[r+1]=='.'))
  			dp[l][r+1] = (dp[l][r+1] + dp[l][r])%m;
  	}
  }
  LL an = 0;
  for(int i = k-1; i<n;i++ )
  	an = (an+dp[0][i])%m;

  cout<<(an)%m<<endl;
  return 0;
}