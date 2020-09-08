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
const int MAXN = 1e3 +5;
const LL m = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][MAXN];

int main(){
  fio();
  LL n,k; cin>>n>>k;
  for1(i,n) dp[1][i] = 1;
  for(int i=2;i<=k;i++){
  	for1(j,n){
  		for(int p=2*j;p<=n;p+=j){
  			dp[i][p] = (dp[i][p]+dp[i-1][j])%m;
  		}
  	}
  }
  LL an = 0;
  for1(i,n){
  	an = (an+dp[k][i])%m;
  }
  cout<<an<<endl;
  return 0;
}