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

LL bit[32];

int main(){
  fio();
  int n; cin>>n;
  forn(i,n){
  	int x; cin>>x;
  	forn(i,32)
  		if(x>>i&1) bit[i]++;
  }
  LL an = 0;
  forn(i,32){
  	LL z = bit[i]*(bit[i]-1)/2;
  	an+=z*(1<<i);
  }
  cout<<an<<endl;
  return 0;
}
