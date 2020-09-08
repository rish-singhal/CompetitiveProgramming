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

int main(){
  fio();
  int n,m; cin>>n>>m;
  if(n>m) {
  	cout<<"YES"<<endl;
  	return 0;
 	}
  bitset<1000> dp;
  forn(i,n){
  	int x; cin>>x;
  	x%=m;
  	dp|=(dp<<(x))|(dp>>(m-x));
  	dp[x] = 1;
  }
  cout<<(dp[0]?"YES":"NO")<<endl;
  return 0;
}