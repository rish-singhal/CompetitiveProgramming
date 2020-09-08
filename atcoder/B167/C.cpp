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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int vis[MAXN];

int main(){
  fio();
  LL n, k; cin>>n>>k;
  vector <LL> v(n+1);
  for1(i,n) cin>>v[i];
 // for1(i,n) cout<<v[i]<<" ";
  LL x = v[1];
  LL co = 1;
  vector<LL> an= {1};
  vis[1]=1;
  //cout<<v[1]<<endl;
  while(vis[x]==0){
  		an.pb(x);
  		vis[x]=1;
  		x = v[x];
  }
   LL xx = 0;
  // vector<LL> an = {3,1,2,5,6,7,8};
  // LL x = 4, k = 4;
  vector <LL> bb, bd;
  for(LL i=0;i<an.size();i++){
  	if(an[i]==x || xx == 1){
  		bd.pb(an[i]);
  		xx = 1;
  	}
  	else{
  		bb.pb(an[i]);
  	}
  }
  if(k<bb.size()){
  	cout<<bb[k]<<endl;
  	return 0;
  }
  k-=(LL)bb.size();
  cout<<(bd[k%((LL)bd.size())])<<endl;
  return 0;
}