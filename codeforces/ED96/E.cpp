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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL tr[4*MAXN];

LL b = 1;

void up(int in, int val){
	tr[in + b] = val;
	in += b;
	while(in > 1){
		tr[in>>1] = tr[in] + tr[in^1];
		in>>=1;
	}
}

LL qu(int in, int ql, int qr, int l = 0, int r = b -1){
	if(r < l) return 0;
	if(ql > r || qr < l)
		return 0;
	if(ql <= l && r <= qr){
		return tr[in];
	}
	int m = (l) + (r-l)/2;
	return qu(2*in, ql, qr, l, m) + qu(2*in+1, ql, qr, m+1,r);
}

int main(){
  fio();
  int n; cin>>n;
  string s; cin>>s;
  while(b <= n) b *= 2;
  forn(i,n){
  	tr[b + i] = 1;
  }
  for(int i = b-1; i>=1; i--){
  	tr[i] = tr[i<<1] + tr[i<<1|1];
  }
  set <int> ss[26];
  forn(i,n){
  	ss[s[i]-'a'].insert(i);
  }
  reverse(all(s));
  LL an = 0;
  for(int i = n - 1; i >= 0; i--){
  	int in = s[i]-'a';
  	auto z = ss[in].rbegin();
  	int ins = *z;
  	ss[in].erase(ins);
  	an += qu(1, ins+1, n-1);
  	up(ins, 0);
  }
  cout<<an<<endl;
  return 0;
}