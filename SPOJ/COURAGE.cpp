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
const LL INF = 1e17;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

struct node{
	LL v, mi;
	void merge(node &a, node &b){
		v = a.v + b.v;
		mi = min(a.mi, b.mi);
	}
};

vector<node> tr;
int b = 1;

node qu(int in, int ql ,int qr, int l = 0, int r = b-1){
	if(ql > r || qr < l)
		return node({0,INF});
	if(ql<=l && r<=qr)
		return tr[in];
	int m = (l+r)/2;
	node an({0,INF});
	auto le = qu(in<<1, ql, qr, l, m);
	auto rq = qu(in<<1|1, ql, qr, m+1, r);
	an.merge(le, rq);
	return an;
}

void up(int in, LL v){
	in+=b;
	tr[in].v = tr[in].mi= v;
	while(in){
		tr[in>>1].merge(tr[in], tr[in^1]);
		in>>=1;
	}
}

int main(){
  fio();
  int n; cin>>n;
  while(b<=n)b*=2;
  tr.assign(2*b, node({0,INF}));
  forn(i,n) {
  	cin>>tr[b+i].v;
  	tr[b+i].mi = tr[b+i].v;
  }
  for(int i = b-1; i>=0; i--){
  	tr[i].merge(tr[i<<1], tr[i<<1|1]);
  }
  int q; cin>>q;
  while(q--){
  	string s; cin>>s;
  	if(s=="EAT"){
		LL x,y; cin>>x>>y;
  		LL v = qu(1, y, y).v - x;
  		up(y, v);
  	}
  	else if(s=="GROW"){
  		LL x,y; cin>>x>>y;
  		LL v = qu(1, y, y).v + x;
  		up(y, v);
  	}
  	else{
  		int l,r; cin>>l>>r;
  		auto xx = qu(1,l,r);
  		scout<<(xx.v - xx.mi)<<endl;
  	}
  }
  return 0;
}