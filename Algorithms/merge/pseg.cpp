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

// [0] [0] 1 1 [0] --> [0 + 5]%2 =>[1]
// [-] [-] 1 1 

struct node{
	int s;
	void merge(node &a, node &b){
		s = a.s + b.s;
	}
};

int b = 1;
vector<node> tr;

void up(int in){
	in+=b;
	tr[in].s = 0;
	while(in){
		tr[in>>1].merge(tr[in], tr[in^1]);
		in>>=1;
	}
}

int qu(int in, int k, int l = 0, int r = b-1){
	if(r < l) return -1;
	if(r==l) return l;
	int m = l + (r-l)/2;
	if(tr[in<<1].s >= k) return qu(in*2, k, l, m);
	return qu(in*2+1, k - tr[in<<1].s , m+1, r);
}


void solve(){
	int n; cin>>n;
	while(b<=n) b*=2;
	tr.resize(2*b,node({0}));
	forn(i,n){
		tr[i+b].s = 1; 
	}
	for(int i = b-1; i>=0; i--)
		tr[i].merge(tr[i<<1], tr[i<<1|1]);
	int left = n;
	int pr = 0;
	vector<int> an(n);
	for1(i,n){
		int vv = (pr+i + left)%left + 1;
		int ind = qu(1,vv);
		an[ind] = i;
		up(ind);
		pr = vv - 1;
		left--;
	}
	for(auto i:an) cout<<i<<" ";
		cout<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}