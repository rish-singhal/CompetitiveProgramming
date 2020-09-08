#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<setprecision(10);
  cout<<fixed;
}

int main(){
  fio();
  int n; cin>>n;
  vector<pair<pair<LL,LL>, LL>> p(n);
  LL m = -1e17, yz = -1e17;
  forn(i,n) cin>>p[i].fi.fi>>p[i].fi.se>>p[i].se;
  forn(i,n)
  	if( m < p[i].fi.se){
  		m = p[i].fi.se;
  		yz = p[i].se;
  	}
  sort(all(p));
  pair<LL,LL> pp = {1,1};
  for(int i = 1; i < n; i++){
  	LL x = - p[i].fi.fi + p[i-1].fi.se;
  	LL y = p[i].se - p[i-1].se;
  	if(x * pp.se > pp.fi * y) pp = {x,y};
  		
  	}
  double ans = (double)m - (double)yz * (double)(pp.fi/(double)pp.se);
  ans -=  (double)p[0].fi.fi - (double)p[0].se * (double)(pp.fi/(double)pp.se);
  cout<<ans<<endl;

  return 0;
}