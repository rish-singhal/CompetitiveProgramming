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
int B = 1;
struct node{
	int op, cl , an;
	void merge(const node& a, const node& b){
		int temp = min(a.op, b.cl);
		an = a.an + b.an + 2*temp;
		op = a.op + b.op - temp;
		cl = a.cl + b.cl - temp;
	}
};

vector<node> tr;

node qu(int in, int ql, int qr, int l = 0 ,int r = B-1){
	if(ql > r || qr < l)
		return node({0,0,0});
	if(ql <= l && r <= qr)
		return tr[in];
	node x({0,0,0});
	int m = (l) + (r-l)/2;
	x.merge(qu(2*in, ql, qr, l, m), qu(2*in+1, ql, qr, m+1,r));
	return x;
}

int main(){
  fio();
  string s; cin>>s;
  while(B<=(int)s.size()) B*=2;
  tr.resize(2*B, node({0,0,0}));
  forn(i,s.size()){
  	if(s[i]==')')
  		tr[i+B].cl = 1;
  	else 
  		tr[i+B].op = 1;
  }
  for(int i = B-1; i>=1; i--){
  	tr[i].merge(tr[i<<1], tr[i<<1|1]);
  }
  int q; cin>>q;
  while(q--){
  	int l, r; cin>>l>>r;
  	l--,r--;
  	cout<<(qu(1,l,r).an)<<endl;
  }
  return 0;
}