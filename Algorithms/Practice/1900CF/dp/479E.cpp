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
const LL mo = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*

abs(x-y) < abs(x - b)

8 , 5 => 6, 10

5 8 ==> 7, 3
y => b+1 , 2*x - (b+1) = y

 x + x  - (b+1)
*/

int main(){
  fio();
  LL n,k,a,b; cin>>n>>a>>b>>k;
  vector<vector<LL>> dp(k+1,vector<LL>(n+1,0));
  dp[0][a] = 1;
  forn(i,k){
  	vector<LL> pr(n+2);
  	for1(j,n){
  		if(j==b) continue;
  		if(j < b){
  			if(i==0)cout<<max(0LL,2*j-(b-1))<<" "<<b<<" ----- "<<j<<endl;
  			pr[max(0LL,2*j-(b-1))] = ( pr[max(0LL,2*j-(b-1))] + dp[i][j])%mo;
  			pr[b] = (pr[b] - dp[i][j] + mo)%mo;
  		}
  		else{
  			pr[min(n, 2*j - (b+1))+1] =  (pr[min(n, 2*j - (b+1))+1] - dp[i][j] +mo)%mo;
  			pr[b+1] = (pr[b+1] + dp[i][j])%mo;
  		}
  	}
  	forn(j,n+1) pr[j] = (pr[j] + pr[j-1])%mo;
  	for1(j,n) dp[i+1][j] = pr[j];
  }
  LL an = 0;
  for1(i,n) an = (an + dp[k][i])%mo;
  cout<<an<<endl;
  return 0;
}