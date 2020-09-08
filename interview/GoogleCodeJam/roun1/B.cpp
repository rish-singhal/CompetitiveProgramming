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

void solve(){
	LL r,c; cin>>r>>c;
  vector< pair<LL, pair<LL,LL> > > v;
  map<LL,LL> rr;
  map<LL,LL> cc;
  for1(i,r){
    for1(j,c){
      LL k; cin>>k;
      v.pb({k,{i,j}});
    }
  }
  sort(v.begin(),v.end());
  vector<LL> su;
  int cnt = 0;
  int bb = v.size()-1;
  map<pair<LL,LL> ,LL> mm;
  LL an = 0;
  while(1){
  for(int i=v.size()-1;i>=0;i--)
  { 

    LL vv  =v[i].fi, er = v[i].se.fi, ec = v[i].se.se;
    if(mm[{er,ec}]==1){
      an+=vv;
     // cout<<an<<endl;
      continue;
    }
   // cout<<vv<<" "<<er<<" "<<ec<<endl;
    if(vv>=rr[er] && vv>=cc[ec]){
      rr[er] = vv;
      cc[ec] = vv;
      an+=vv;
      mm[{er,ec}]=1;
      cnt++;
    }
  }
 // cout<<cnt<<endl;
  rr.clear(), cc.clear();
}
  cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t){
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}