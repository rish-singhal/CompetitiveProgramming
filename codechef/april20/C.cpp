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
const LL m = 998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) return an*a%m;
	return an;
}

int nd[3][4][4] = {{{0,0,0,0}, {0,1,2,3}, {0,2,2,0},{0,3,0,3}},
				 {{0,1,2,3}, {1,1,1,1}, {2,1,2,1},{3,1,1,3}},
				 {{0,1,2,3}, {1,0,3,2}, {2,3,0,1},{3,2,1,0}}};

map<char,int> mf;

void solve(){
	LL an[4] = {1,1,1,1};
	string s; cin>>s;
	stack<char> ss;
	LL q = 1;
	for(auto i:s){
		if(i=='#') q = (q*4)%m;
		else if(i==')'){
			int op = mf[ss.top()];
			ss.pop();
			ss.pop();
			LL ann[4] = {0,0,0,0};
			forn(k,4)
				forn(j,4)
					ann[nd[op][k][j]] = (ann[nd[op][k][j]] + (an[k]*an[j])%m)%m;
			forn(k,4) an[k] = ann[k];		
		}
		else ss.push(i);
	}
	q = po(q,m-2);
	forn(i,4) an[i] = (an[i]*q)%m;
	forn(i,4) cout<<an[i]<<" ";
	cout<<endl;
}

int main(){
  fio();
  mf['&'] = 0, mf['|'] = 1, mf['^'] = 2;
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}