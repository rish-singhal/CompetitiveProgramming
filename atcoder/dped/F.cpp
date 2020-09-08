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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int dp[MAXN][MAXN];
int fr[MAXN][MAXN];

int main(){
  fio();
  string s,t; cin>>s>>t;
  int n = s.size();
  int m = t.size();
 
  forn(i,n){
  		forn(j,m){
  			if(s[i]==t[j]){
  			 if((i>=1 &&j>=1?dp[i-1][j-1]:0) + 1 > dp[i][j]){
  			 	dp[i][j] = (i>=1 &&j>=1?dp[i-1][j-1]:0) + 1;
  			 	fr[i][j] = 2;
  			 }
  			}
  			if((i>=1?dp[i-1][j]:0) > dp[i][j]){
  				dp[i][j] = (i>=1?dp[i-1][j]:0);
  			 	fr[i][j] = 1;
  			}
  			if(( j>=1?dp[i][j-1]:0) > dp[i][j]){
  				dp[i][j] =  j>=1?dp[i][j-1]:0;
  			 	fr[i][j] = 0;
  			}
  		}
  }
  string an = "";
  int x = n-1, y = m-1;
  while((x>=0)&&(y>=0)){
  	if(fr[x][y]==0){
  		y--;
  	}
  	else if(fr[x][y]==1){
  		x--;
  	}
  	else{
  		an+=s[x];
  		x--,y--;
  	}
  }
  reverse(all(an));
  cout<<an<<endl;
  return 0;
}