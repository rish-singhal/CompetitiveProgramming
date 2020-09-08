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

int b = 1;
struct node{
	int v, l, r, lazy;
	void merge(node &a, node &b){
		v = a.v + b.v;
		l = min(a.l, b.l);
		r = max(a.r, b.r);
	}
	void flip(){
		lazy ^= 1;
		v = (r-l+1) - v;
	}
};

vector<node> tr;

void up(int in, int ql, int qr, int l = 0, int r = b-1){
	if(ql>r || qr<l) return;
	if(ql<= l && r <= qr)
		return tr[in].flip();
	int m = (l + r)/2;
	if(tr[in].lazy){
		for(int i:{2*in, 2*in+1})
			tr[i].flip();
		tr[in].lazy = 0;
	}
	up(in*2, ql, qr, l , m);
	up(in*2 + 1, ql, qr, m+1 , r);
	tr[in].merge(tr[in<<1],tr[in<<1|1]);
}

int qu(int in, int ql, int qr, int l = 0, int r = b-1){
	if(ql>r || qr<l) return 0;
	if(ql<= l && r <= qr)
		return tr[in].v;
	int m = (l + r)/2;
	if(tr[in].lazy){
		for(int i:{2*in, 2*in+1})
			tr[i].flip();
		tr[in].lazy = 0;
	}
	return qu(in*2, ql, qr, l , m)+ qu(in*2 + 1, ql, qr, m+1 , r);
}

int main(){
  fio();
  int n,q; cin>>n>>q;
  while(b<=n) b*=2;
  tr.assign(2*b,node({0,0,0,0}));	
  forn(i,n)
  	tr[i+b].l = tr[i+b].r = i;
  for(int i = b-1; i>=0; --i)
  	tr[i].merge(tr[i<<1], tr[i<<1|1]);
  while(q--){
  	int x; cin>>x;
  	int l,r; cin>>l>>r;
  	if(x==1){
  		cout<<qu(1, l , r)<<endl;
  	}
  	else{
  		up(1, l ,r);
  	}
  }
  return 0;
}