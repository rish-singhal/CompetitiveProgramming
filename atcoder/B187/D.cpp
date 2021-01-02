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
// check MAXN

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}



int main(){
  fio();	
  int n ;cin>>n;
  vector<pair<LL,pair<LL,LL>>> v(n);
  forn(i,n){
  	cin>>v[i].se.fi >> v[i].se.se;
  	v[i].fi = 2*v[i].se.fi + v[i].se.se;
  }
  sort(all(v));
  vector <LL> s(n);
  forn(i,n){
  	s[i] = v[i].se.fi + (i>=1?s[i-1]:0);
  }
  LL su = 0;
  for(int i = 0; i < n; i++)
  {
  	su += v[n-i-1].se.fi + v[n-i-1].se.se;
  	if(su > s[n-i-2]){
  		cout << i + 1 << endl;
  		return 0;
  	}
  }
  cout << n << endl;
  return 0;
}
