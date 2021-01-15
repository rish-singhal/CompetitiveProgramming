#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 2e5 +5;
const LL INF = 1e17;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


// struct node{
// 	LL val, mi, ma;
// 	node(LL val = 0, LL mi = INF, LL ma = -INF): val(val), mi(mi), ma(ma){
// 		//mi = ma = val;
// 	}
// 	node(node *a, node *b): val(0){
// 		//cout << a->val << endl;
// 		mi = min(a->mi, b->mi);
// 		ma = max(a->ma, b->ma);
// 		val = a->val + b->val;
// 	}
// 	void merge(node *a, node *b){
// 		mi = min(a->mi, b->mi);
// 		ma = max(a->ma, b->ma);
// 		val = a->val + b->val;
// 	}
// };

// vector<node*> tr;
// //LL arr[MAXN];

// node* qu(int in, int ql, int qr, int l, int r){
// 	if(qr < l ||  r < ql) 
// 		 		return tr[in];
// 	int m = l + (r-l)/2;
// 	return new node(qu(2*in, ql, min(qr,m), l, m),qu(2*in+1, max(m+1,ql), qr, m+1, r));
// }

// void build(int in, int l, int r){
// 	if(l==r){
// 		tr[in] = new node(arr[l]);
// 		//debug(in, l);
// 		return;
// 	}
// 	int m = (l+r)/2;
// 	build(2*in,l,m);
// 	build(2*in+1,m+1,r);
// 	tr[in] = new node(tr[2*in], tr[2*in+1]);
// }

// void up(int in, int l, int r, int pos, int val){
// 	if(l==r){
// 		tr[in]->val = val;
// 		return;
// 	}
// 	int m = (l+r)/2;
// 	if(pos <= m){
// 		up(2*in, l, m, pos, val);
// 	}
// 	else up(2*in+1, m+1, r, pos, val);
// }


void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector <LL> v(n+1);
//	tr.clear();
	
//	LL B = 1;
  //	while(B<=(n+1)) B*=2;
  //	tr.assign(4*(n+1), new node());

	v[0] = 0;
	//tr[B] = new node(v[0], v[0], v[0]);
	//arr[0] = v[0];
	for(int i = 0; i  < s.size(); i++)
		{
			if(s[i] == '-')
				v[i+1] = v[i] - 1;
			else if(s[i] == '+')
				v[i+1] = v[i] + 1;
	//		arr[i+1] = v[i+1];

			//tr[B + i + 1] = new node(v[i+1], v[i+1], v[i+1]);
		}

	vector<LL> mlef(n+1), milef(n+1);
	mlef[0] = v[0];
	milef[0] = v[0];
	for(int  i = 1; i <= n ; i ++){
		milef[i] = min(v[i], milef[i-1]);
		mlef[i] = max(v[i], mlef[i-1]);
	}
//cout << " 01 " << endl;
	
	vector<LL> mrig(n+1), mirig(n+1);

	mrig[n] = v[n];
	mirig[n] = v[n];
	for(int  i = n - 1; i >= 0 ; i --){
		mirig[i] = min(v[i], mirig[i+1]);
		mrig[i] = max(v[i], mrig[i+1]);
	}

//cout << " 01 " << endl;
	// for(int  i = 0; i  <= n; i ++)
	// 	cout << mrig[i] << " ";
	// cout << endl;

	while(m --){
		int l, r; cin >> l >> r;
		//node* anl = qu(1, 0, l - 1, 0, B-1);
		//node* anr = qu(1, r+1, n, 0, B-1);
		LL ans = mlef[l-1] - milef[l-1] + 1;
		
		//cout << ans << " -- " << endl;

		if(r + 1 <= n){
			LL rma = mrig[r+1] - v[r] + v[l-1]; 
			LL rmi = mirig[r+1] - v[r] + v[l-1];

		//	cout << r << " ** "<<rma << " " << rmi << " -- "<< "  " << v[r]<<endl;
			if(rma <  milef[l-1] || rmi > mlef[l-1]){
				ans += rma - rmi  + 1;
			}
			else{
				ans = max(rma, mlef[l-1]) - min(rmi,  milef[l-1]) + 1;
			}
		}
		cout << ans << endl;
	}
	//for(auto i:tr)
		//delete i;
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	solve();
  }

  return 0;
}