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
const int MAXN = 3e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int dsu[MAXN];

int pa(int u){
	return dsu[u]<0?u:dsu[u]=pa(dsu[u]);
}

void join(int u,int v){
	u = pa(u), v= pa(v);
	if(u==v) return;
	dsu[v] += dsu[u];
	dsu[u] = v;
}

int main(){
  fio();
  int n; cin>>n;
  forn(i,MAXN) dsu[i] = -1;
  vector<char> an(MAXN, '?');
  int ma = 0;
  forn(i,n){
  	string s; cin>>s;
  	int k; cin>>k;
  	forn(j,k){
  		int in; cin>>in;
  		int len = s.size();
  		ma = max(in + len - 1, ma);
  		for(int kk = 0; kk < len; ){
  			an[in + kk] = s[kk];
  			join(in + kk, in + kk + 1);
  			kk = pa(in + kk) - in;
  		}
  	}
  }
  int slen = ma;
  for1(i,slen){
  	cout<<(an[i]=='?'?'a':an[i]);
  }
  cout<<endl;
  return 0;
}