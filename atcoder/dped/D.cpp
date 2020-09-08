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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN];

int main(){
  fio();
  int n,w; cin>>n>>w;
  forn(i,n){
  	LL a,b; cin>>a>>b;
  	for(LL i = w; i>=0;i--){
  		if(i+a>w) continue;
  		dp[i+a] = max(dp[i+a], dp[i] + b);
  	}
  }
  LL an = 0;
  for1(i,w){
  	an = max(an, dp[i]);
  }
  cout<<an<<endl;
  return 0;
}