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
  for1(i,MAXN-1) dp[i] = 1e18;
  forn(i,n){
  	LL a,b; cin>>a>>b;
  	for(LL i = MAXN; i>=0;i--){
  		if(i+b>MAXN) continue;
  		dp[i+b] = min(dp[i+b], dp[i] + a);
  	}
  }
  LL an = 0;
  forn(i,MAXN){
  	if(dp[i]>w) continue;
    an = max(an,(LL) i);
  }
  cout<<an<<endl;
  return 0;
}