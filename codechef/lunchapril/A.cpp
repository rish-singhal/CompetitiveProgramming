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
const LL mm = 998244353;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%mm;
	if(n&1) return an*a%mm;
	return an;
}

void solve(){
	LL n; cin>>n;
	map<LL,LL> cnt;
    LL su = 0;
    forn(i,n) {
		LL k; cin>>k;
		cnt[k]++;
		su++;
	}
	LL an = 0;
	LL suu = 0;
	LL pro = 1;
	for1(i, MAXN ){
		suu += cnt[i];
		LL zz  = po(2,(su-suu))%mm;
		an =  (an + ((pro)*(zz)%mm)*i%mm)%mm;
		if(cnt[i]==0) break;
		pro = (pro*(po(2,cnt[i])-1)%mm)%mm;
	}
	cout<<an<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}