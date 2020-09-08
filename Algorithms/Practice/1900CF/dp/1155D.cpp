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
const int MAXN = 3e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*

1, 2 , [3, 4, 5 ]
	   [-ve * val]

ma2 is with negative stuff *= -ve val...

// 				[ ...+ve].[-ve ...... -ve].[+ve... ]  		

dp[n][2][2]
		
dp[n][1][0] <= dp[n-1][0][0] + dp[n-1][1][0]
dp[n][0][1] <= dp[n-1][1][0]
dp[n][0][0] <= dp[]

*/

LL dp[MAXN][3];

int main(){
  fio();
  LL n,x; cin>>n>>x;
  vector<LL> v(n);
  forn(i,n) cin>>v[i];
  LL an = 0;
  forn(i,n){
  	if(i==0){
  		dp[i][1] = x*v[i], dp[i][0] = max(v[i],0LL), dp[i][2] = 0;
  		
  	}
  	else{
	  	dp[i][1] = x*v[i] + max({0LL, dp[i-1][0], dp[i-1][1]}); // we can start from nowhere
	  	dp[i][2] =  max(v[i] + dp[i-1][1], v[i] + dp[i-1][2]);
	  	dp[i][0] = max(v[i] + dp[i-1][0], v[i]);
	}
	an = max(an, *max_element(dp[i], dp[i]+3));
  }
  cout<<an<<endl;
  return 0;
}