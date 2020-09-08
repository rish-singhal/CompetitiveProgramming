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

LL co[MAXN];
int main(){
  fio();
  LL n,m,x; cin>>n>>m>>x;
  vector <vector <LL> > v(n);
  forn(i,n){
  	cin>>co[i];
  	forn(j,m){
  		LL xx; cin>>xx;
  		v[i].pb(xx);
  	}
  }

LL  an  =1e18;
  forn(msk,1<<n){
  	vector <LL> mm(m);
  	LL kk= 0;
  	forn(i,n){
  		if(msk>>i&1){
  			kk+=co[i];
  			forn(j,m){
  				mm[j]+=v[i][j];
  			}
  		}
  	}
  	int bb = 1;
  	forn(i,m){
  		bb &= mm[i]>=x;
  	}
  	if(bb){
  		an = min(an,kk);
  	}
  }
  if(an==1e18) cout<<-1<<endl;
  else cout<<an<<endl;
  return 0;
}