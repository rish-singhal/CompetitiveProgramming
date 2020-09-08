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
const int MAXN =  305;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int C[MAXN][MAXN], sum[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
  fio();
  int N,K,M; cin>>N>>K>>M;
  N++;
  for(int i=0;i<=N;i++)
    for(int j=0;j<=i;j++)
      C[i][j] = j>0?(C[i-1][j-1] + C[i-1][j])%M : 1;
  forn(i,K+1) dp[1][i]=1;
  for(int i = K;~i;i--)
    sum[1][i]= (sum[1][i+1] + dp[1][i])%M;
  for(int n=2;n<=N;n++){
    for(int x=0;x<=K;x++)
      for(int k=1; k<n;k++)
        dp[n][x] = (dp[n][x] + (LL)sum[k][x+1]*C[n-2][k-1]%M*dp[n-k][x])%M;
    for(int i = K;i>=0;--i)
       sum[n][i] = (sum[n][i+1] + dp[n][i])%M;
  }
  cout<<dp[N][0]<<endl;
    return 0;
}

