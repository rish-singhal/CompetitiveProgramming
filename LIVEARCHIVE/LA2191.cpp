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

int n, b = 1; 
struct node{
	LL v;
	void merge(node &a, node &b){
		v = a.v + b.v;
	}
};

vector<node> tr;

void up(int l, LL v){
	tr[l+b].v = v;
	l+=b;
	while(l){
		tr[l>>1].merge(tr[l], tr[l^1]);
		l>>=1;
	}
}

LL qu(int in, int l, int r, int xl = 0, int xr = b-1){
	if(l > xr || r < xl)
		return 0;
	if(l <= xl && xr <= r)
		return tr[in].v;
	int m = (xl) + (xr-xl)/2;
	return qu(in*2, l, r, xl, m) + qu(in*2 + 1, l , r, m+1, xr);
}


void solve(){
   b = 1;
   while(b<=n)  b*=2;
   tr.resize(2*b,node({0}));
   forn(i,n){
   	cin>>tr[i+b].v;
   }
   for(int i=b-1;i>=0;i--)
   	 tr[i].merge(tr[i<<1], tr[i<<1|1]);
   string s; 
   while(1){
   	cin>>s;
   	if(s=="END") return;
   	if(s[0]=='M'){
   		int l,r; cin>>l>>r;
   		l--, r--;
   		cout<<qu(1, l, r)<<endl;
   	}
   	else {
   		LL l, v; cin>>l>>v;
   		l--;
   		up(l,v);
   	}
   }	
}

int main(){
  fio();
  int cnt = 1;
  while(1){
  	cin>>n;
  	if(n==0) return 0;
  	if(cnt>1) cout<<endl;
  	cout<<"Case "<<cnt++<<":"<<endl;
  	solve();	
  }
  return 0;
}