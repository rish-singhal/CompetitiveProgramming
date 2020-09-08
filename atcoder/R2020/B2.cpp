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
  vector<pair<LL,LL>> v(2);
  forn(i,2) cin>>v[i].fi>>v[i].se;
  LL t; cin>>t;
  LL vi = v[0].se - v[1].se;
  if((abs(v[0].fi-v[1].se)) == 0){
    cout<<"YES"<<endl;
    return 0;
  }
  if(vi >= ((abs(v[0].fi-v[1].se) + t - 1)/t) ){
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
  return 0;
}