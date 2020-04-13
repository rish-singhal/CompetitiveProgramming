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
const int MAXN = 1e7 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL cnt[MAXN];
LL pr[MAXN];

int main(){
  fio();
  LL n; cin>>n;
  forn(i,n) {
  	LL k; cin>>k;
  	cnt[k]++;
  }
  for(LL i = 2;i<MAXN; i++){
  	if(pr[i]==1){
  		cnt[i] = 0;
  	 continue;
  	}
  	for(LL j = 2*i; j<MAXN; j+=i){
  		cnt[i]+=cnt[j];
  		pr[j] = 1;
  	}
  }
  for1(i,MAXN-1)
  	cnt[i]+=cnt[i-1];
  int q; cin>>q;
  while(q--){
  	LL l,r; cin>>l>>r;
  	r = min((LL)1e7,r);
  	l = min((LL)1e7,l);
  	cout<<cnt[r]-cnt[l-1]<<endl;
  }
  return 0;
}