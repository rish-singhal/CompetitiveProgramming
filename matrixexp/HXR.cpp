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
const int MAXN = 5e2 + 5;
const int N = 500;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n, k;
bitset<N> row[MAXN], col[MAXN];
bitset<N> mrow[MAXN], mcol[MAXN];

void mul_mat(bitset<N> *r, bitset<N> *c, bitset<N> *c2){
	bitset<N> rx[MAXN], cx[MAXN];
	forn(i,n)
		forn(j,n)
			rx[i][j] = cx[j][i] = (r[i]&c2[j]).count() &1;
	forn(i,n) r[i] = rx[i], c[i] = cx[i];
}

void expo(int k){
	forn(i,n) mrow[i][i] = mcol[i][i] = 1;
	while(k){
		if(k&1) mul_mat(mrow,mcol,col);
		mul_mat(row,col,col);
		k>>=1;
	}
}

void solve(){
	cin>>n>>k;
	vector<LL> v(n);
	forn(i,n) cin>>v[i];
	forn(i,n)
		forn(j,n)
			row[i][j] = col[i][j] = mrow[i][j] = mcol[i][j] = 0;
	forn(i,n){
		int l,r; cin>>l>>r;
		for(int p = l-1; p < r; p++)
			row[i][p] = col[p][i] = 1;
	}
	expo(k-1);
	forn(i,n){
		LL pp = 0;
		forn(j,n){
			if(mrow[i][j]) pp ^= v[j];
		}
		cout<<pp<<" ";
	}
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