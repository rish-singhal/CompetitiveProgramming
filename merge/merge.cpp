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

struct node{
	vector<int> v;
	void merge(node& a, node& b){
		std::merge(all(a.v), all(b.v), back_inserter(v));
	}
};

int b = 1;
vector<node> t;
int qu(int in, int ql, int qr, int k, int l = 0 ,int r = b-1){
	if( r < ql || qr < l)
		return 0;
	if(ql<=l && r<=qr)
		return 	upper_bound(all(t[in].v),k) - t[in].v.begin();
	int m = (l+r)/2;
	return qu(in<<1, ql, qr, k, l, m) + qu(in<<1|1, ql ,qr, k, m+1, r);
}

void build

int main(){
  fio();
  int n; cin>>n;
  while(b<=n) b*=2;
  t.assign(2*b, node());
  forn(i,n){
  	int x; cin>>x;
  	t[i+b].v.pb(x);
  }
  for(int i = b-1; i>=0; i--){
  	t[i].merge(t[i<<1], t[i<<1|1]);
  }
  int q; cin>>q;
  while(q--){
  	int l,r,k; cin>>l>>r>>k;
  	l--,r--;
  	cout<<qu(1, l ,r, k)<<endl;
  }
  return 0;
}