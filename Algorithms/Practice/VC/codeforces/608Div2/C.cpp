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

LL dx[4] = {0,1,0,-1};
LL dy[4] = {1,0,-1,0};




int main(){
  fio();
  LL n, sx, sy; cin>>n>>sx>>sy;
  vector<LL> an(4,0);
  forn(i,n){
  	LL u,v; cin>>u>>v;
  	forn(j,4){
  		LL x = sx+dx[j];
  		LL y = sy+dy[j];
  		if(x<0 || x>1e9 || y<0 || y>1e9){
  			continue;
  		}
  		if(abs(x-u) + abs(y-v) < abs(u-sx) + abs(v-sy)){
  			an[j]++;
  		}
  	}
  }
  LL k = 0;
  int p = 0;
  forn(j,4){
  	LL x = sx+dx[j];
  	LL y = sy+dy[j];
  	if(x<0 || x>1e9 || y<0 || y>1e9){
  			continue;
  	}
  	k = max(k,an[j]);
  	if(k<an[j]){
  		k = an[j];
  		p = j;
  	}
  }
  cout<<k<<endl;
  cout<<sx+dx[p]<<" "<<sy+dy[p]<<endl;
  
//  }
  return 0;
}