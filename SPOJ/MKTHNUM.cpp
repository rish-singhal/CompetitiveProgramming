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

// 1 5 2 4 7 6 8 3
// MKTHNUM

struct node{
	node *l, *r;
	int s;
	node(int sum = 0): l(NULL), r(NULL), s(sum){}
	node(node *a, node *b): l(a), r(b){
		if(a) s += a->s;
		if(b) s += b->s;
	}
};

vector<node*> vv;
int n,m;

node* up(node *ro, int pos, int v, int ll = 0, int rr = n-1){
	if(ll == rr) return new node(v);
	int m = (ll + rr)/2;
	if(pos <= m)
		return new node(up(ro->l, pos, v, ll, m), ro->r);
	return new node(ro->l, up(ro->r, pos, v, m+1, rr));
}	

node* build(int ll=0, int rr= n-1){
	if(ll == rr) return new node();
	int m = (ll+rr)/2;
	return new node(build(ll,m), build(m+1,rr));
}

int qu(node *vr, node *vl , int k, int ll = 0, int rr = n-1){
	if(ll == rr) return ll;
	int m = (ll+rr)/2;
	int lval = vr->l->s - vl->l->s;
	if(lval>=k) return qu(vr->l, vl->l , k, ll, m);
	return qu(vr->r, vl->r , k - lval, m+1, rr);
}

int main(){
  scanf("%d%d",&n,&m);
  vv.pb(build());
  vector<pair<int,int>> comp;
  forn(i,n){
  	int x; scanf("%d",&x);
  	comp.emplace_back(x,i);
  }
  sort(all(comp));
  vector<int> nv(n);
  vector<int> ind(n);
  forn(i,n){
  		nv[comp[i].se] = i;
  		ind[i] = comp[i].fi;
  }
  forn(i,n){
  	vv.pb(up(vv.back(),nv[i],1));
  }
  
  while(m--){
  	int l,r,k; scanf("%d%d%d",&l,&r,&k);
  	printf("%d\n",ind[qu(vv[r], vv[l-1], k)]);
  }  
  return 0;
}