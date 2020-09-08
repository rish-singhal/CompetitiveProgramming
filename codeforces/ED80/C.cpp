#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL mm =1e9 +7;
LL dp[15][1005], dp2[15][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n,m ;cin>>n>>m;
	for(int i=1;i<=n;i++) {
		dp[1][i] = 1;
		dp2[1][i] = 1;
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = 0;
			for(int k=j;k<=n;k++){
				dp[i][j] = ( dp[i][j] + dp[i-1][k] )%mm;
			}
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp2[i][j] = 0;
			for(int k=j;k>=1;k--){
				dp2[i][j] = ( dp2[i][j] + dp2[i-1][k] )%mm;
			}
		}
	}
	LL an  = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			an = ( an + (dp[m][j]*dp2[m][i])%mm )%mm;
		}
	}
	
	cout<<an<<endl;
	return 0;
}


