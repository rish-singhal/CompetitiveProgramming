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
  LL n,q; cin>>n>>q;
  vector<LL> g(n+1);
  for(LL i=n;i>=1;i--){
  	g[i] = (n/i)*(n/i);
  	for(LL j = 2*i; j<=n ; j+=i)
  		g[i]-=g[j];
  }
  for1(i,n) g[i] = (g[i]-1)/2;
  while(q--){
  	LL k; cin>>k;
  	if(k>n) cout<<0<<endl;
  	else cout<<g[k]<<endl;
  }
  return 0;
}