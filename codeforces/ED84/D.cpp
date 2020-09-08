#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL m =998244353;

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) return an*a%m;
	return an;
}

void solve(){
	LL n; cin>>n;
	for(LL i=1;i<=n;i++){
		LL an =0;
		if(n==i){
			cout<<10<<" ";
		}
		else if(i==n-1){
			cout<<180<<" ";
		}
		else{
			if((n-i)>=2){
			 an = ((180LL*po(10, n - (i+1))%m) + (810LL*po(10, n - (i + 2))%m)*(n-i - 1)%m )%m;
			 cout<<an<<" ";
		 }
	 }
 }
 cout<<endl;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

