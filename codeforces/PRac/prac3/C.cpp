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
LL mm;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][MAXN];
// m lines, b bugs 


int main(){
  fio();

  LL n,m,b; cin>>n>>m>>b>>mm;

  dp[0][0] = 1;

  for1(i,n){
  	LL a; cin>>a;
  	for(LL x = 0; x<=m; x++){
  		for(LL bu=0; bu<=b; bu++){
  			if(bu+a<=b && x+1<=m) dp[x+1][bu+a] = ( dp[x+1][bu+a] + dp[x][bu] )%mm;
  		}
  	}
  }
  LL an = 0;
  for(LL bu=0; bu<=b; bu++) an = (an + dp[m][bu])%mm;
  	cout<<an<<endl;

  return 0;
}