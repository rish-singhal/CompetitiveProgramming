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

LL gcd(LL a, LL b){
	return b?gcd(b,a%b):a;
}

LL y,b;
LL x,a; 
vector<LL> v;
LL lx;
LL k; 

bool chk(int m){
	vector<LL> vv;
	for1(i,m){
		if((i%lx==0)){
			vv.pb(x+y);
		}
		else if(i%a==0){
			vv.pb(x);
		}
		else if(i%b==0){
			vv.pb(y);
		}
	}
	sort(all(vv));
	reverse(all(vv));
	LL ann = 0;
	for(int i=0;i<vv.size();i++){
		ann += (v[i]*vv[i])/100;
	}
	return ann>=k;
}


void solve(){
	int n; cin>>n;
	v.assign(n,0);
	forn(i,n) cin>>v[i];
	sort(all(v));
	reverse(all(v));
	cin>>x>>a;
	cin>>y>>b;
	cin>>k;
	lx = (a*b)/gcd(a,b);
	LL l = 0, r = n+1;
	while(l<r){
		LL m = (l) + (r-l)/2;
		if(chk(m)){
			r = m;
		}
		else l = m+1;
	}
	if(l==n+1){
		cout<<-1<<endl;
	}	
	else cout<<l<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}