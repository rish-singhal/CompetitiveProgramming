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
  int t; cin>>t;
  while(t--){
  int n; cin>>n;
  LL b = 1;
  LL c1 = 0, c2 =0;
  vector <int> v(n);
  forn(i,n) cin>>v[i];
  forn(i,n){
  	int k; cin>>k;
  	if(k>v[i]) b&=c1;
  	if(k<v[i]) b&=c2;
  	if(v[i]==-1) c2 = 1;
  	if(v[i]==1) c1 = 1;
  }
  cout<<(b?"YES\n":"NO\n");
}
  return 0;
}