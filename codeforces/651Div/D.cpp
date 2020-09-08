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
// (k/2) + 1 maxx..
// X .. X .. X ... X .. X .. X
int main(){
  fio();
  int n,k; cin>>n>>k;
  vector<pair<LL,int>> v;
  forn(i,n){
  	LL x; cin>>x;
  	v.pb({x,i});
  }
  sort(all(v));
  vector<pair<int,LL>> v2;
  forn(i,k){
  	v2.pb({v[i].se, v[i].fi});
  }
  sort(all(v2));
  // k = even, odd
  // k/2;
  
  return 0;
}