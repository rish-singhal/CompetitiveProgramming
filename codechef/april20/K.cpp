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
const int MAXN = 1e6+5;
const LL M = 1e9+7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%M;
	if(n&1) return an*a%M;
	return an;
}

// imported

long long isqrt(unsigned long long x) {
    int sh = __builtin_ctzll(x);
    x >>= (sh&~1);
    
    if (x&6) return -1;
    
    int i;
    const int ITERATIONS = 5; 
    unsigned long long z = (3-x)>>1, y=x*z;
    for (i=0; i<ITERATIONS; i++) {
        unsigned long long w = (3 - z*y) >> 1;
        y *= w;
        z *= w;
    }
    assert(x==0 || (y*z == 1 && x*z == y));
    
    if (y & (1ull<<62)) y = -y;
    y &= ~(1ull<<63);
    
    if (y >= 1ull<<32) return -1;
 
    return y<<(sh/2);
}



//vector<LL> v(1000);
vector<LL> vv;
vector<LL> pvv;
LL vin = po(6,M-2);
vector <LL> sfree(MAXN);

LL calc2(LL n){
	if(n<2) return 0;
	LL an = 1;
	n%=M;
	an = (an*n)%M;
	an = (an*(n+1))%M;
	an = (an*(2*n+1))%M;
	an = (an*vin)%M;
	an = (an-1+M)%M;
	return an;
}

LL calc(LL l, LL r){
	LL rr = upper_bound(vv.begin(),vv.end(),r) - vv.begin() - 1;
	LL ll = lower_bound(vv.begin(),vv.end(),l) - vv.begin() - 1;
//	cout<<(rr<0?0:pvv[rr])<<" --- "<<(ll<0?0:pvv[ll])<<endl;
	LL an = ((rr<0?0:pvv[rr]) - (ll<0?0:pvv[ll]) + M)%M;
	return an;
}

void solve(){
	LL n; cin>>n;
	LL an = 0;
	
    //set<LL> s;
    LL cub = 0;
    while(cub*cub*cub<=n) cub++;
    cub--;
	for(LL i=2;i*i*i<=n;i++){
	  	if(sfree[i]) continue;
	  	LL j = (i*i)%M;
	  	LL nn = n/(i*i); 
	  	while(nn>cub){
	  		//if(ma[j]!=1){
	  		    an = (an + ((j%M)*(nn%M))%M)%M;
	  		// ma[j] = 1;}
	  		// else break;
	  	//	cout<<j<<" --"<<nn<<endl;
	  		j = (j*i)%M;
	  		nn/=i;
	  		//if(j<=cub && ) break;
	  	}
  	}
 // cout<<" ---  "<<an<<endl;
  for(LL i=1;i*i*i<=n;i++){
  	LL l = (n/(i+1))+1;
  	LL r = (n/i);
  	LL v = i;
  	LL fl =(LL) sqrtl(l+.5);
  	LL fr =(LL) sqrtl(r+.0);
  	if(isqrt(l)!=-1) fl = max(0LL,fl-1);
  	LL cntz = (calc2(fr) - calc2(fl) + M)%M;
  	an = ( an + (v*cntz)%M )%M;
  	LL vvx = calc(l,r);
  	an = (an + (v*vvx)%M)%M;
  	//cout<<v<<" "<<l<<" "<<r<<" "<<cntz<<" "<<vvx<<endl;
  }
  an = (an + n%M)%M;
  if(an<0) an+=M;
  cout<<an<<endl;

}

int main(){
  fio();
  for(LL i=2;i<=1e6+5;i++){
  	LL j = i*i*i; 
  	LL cnt = 3;
  	while(j<=1e18+5 && cnt<=60 ){
  		if(isqrt(j)==-1) vv.pb(j);
  		if(i<=((1e18+5)/j)){
  			j*=i;
  			cnt++;
  		}
  		else break;
  	}
  }

  for(LL i=2;i<=MAXN;i++){
  	if(sfree[i]) continue;
  	LL k = i*i;
  	for(LL j=k; j<=MAXN; j*=i){
  		sfree[j] =1;
  	}
  }

  sort(vv.begin(),vv.end());
  vv.erase(unique(vv.begin(),vv.end()),vv.end());
  //for(auto i:vv) cout<<i<<" "<<endl;
  pvv.resize(vv.size());
  forn(i,vv.size()){
  	pvv[i] = ((i>=1?pvv[i-1]:0)%M + (vv[i]%M))%M;
  }
  //forn(i,10) cout<<pvv[i]<<" ";
  //cout<<endl;
 // bool b =true;
  //forn(i,vv.size()-1) b&=vv[i]<=vv[i+1];
 // cout<<vv.size()<<endl;
  //cout<<(isqrt(1e18))<<endl;
  cout << fixed;
  int t; cin>>t;
  while(t--){
  	//for1(i,1000)solve(i);
  	solve();
  }
  return 0;
}