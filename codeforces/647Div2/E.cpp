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
const LL mo = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%mo;
	if(n&1) return (an*a)%mo;
	return an;
}


int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL n, p; cin>>n>>p;
  	map<LL,LL> cnt;
  	for(int i=0;i<n;i++){
  		LL k; cin>>k;
  		cnt[k]++;
  	}
  	vector<pair<LL,LL>> v;
  	for(auto i:cnt){
  		v.pb(i);
  	}
  	for(int i = v.size()-1; i>=0; i--){
  		v[i].se%=2;
  		if(v[i].se==1) break;
  	}
  	//cout<<an<<endl;
  }
  return 0;
}


if(p==1){
  	// 	if(n&1) cout<<1<<endl;
  	// 	else cout<<0<<endl;
  	// 	cout<<" --- "<<endl;
  	// 	continue;
  	// }
  	// for(auto i:cnt){
  	// 	LL k = p;
  	// 	int c = 0;
  	// 	while(k <= i.se){
  	// 		k*=p;
  	// 		c++;
  	// 	}
  	// 	k/=p;
  	// 	cnt[i.fi + c]++; 
  	// 	cnt[i.fi]-=k;
  	// }
  	// vector<pair<LL,LL>> v;
  	// for(auto i:cnt){	
  	// 	if(i.se) v.pb({i.fi,i.se});
  	// }
  	// for(auto i:v) cout<<i.fi<<" "<<i.se<<endl;
  	// 	cout<<" --- "<<endl;
  	// int sz = v.size();
  	// int pz = sz-1;
  	// LL an = 0;
  	// for(int k = sz-1;k>=0;k--){
  	// 	v[k].se %= 2;
  	// 	if(v[k].se!=0) {
  	// 		pz = k;
  	// 		cout<<v[k].se<<" -- "<<endl;
  	// 		an = po(p,v[k].fi);
  	// 		break;
  	// 	}
  	// }
  	// pz--;
  	// if(pz<0){
  	// 	cout<<an<<endl;
  	// 	continue;
  	// }
  	// for(int pp = pz; pp>=0;pp--){
  	// 	an = (an - (v[pp].se*po(p,v[pp].fi))%mo)%mo;
  	// 	an = (an+mo)%mo;
  	// }