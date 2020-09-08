#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL mm =1e9 +7;

void solve(){
	int n,m,k; cin>>n>>m>>k;
	//cout<<"rw"<<endl;
	vector <pair<pair<int,int> ,pair<int,int> > > v(k), f(k);
	forn(i,k){
		int a,b; cin>>a>>b;
		v[i].fi = {a,b};
	}
	int cnt = 0;
	forn(i,k){
		int a,b; cin>>a>>b;
		v[i].se = {a,b};
		if(v[i].fi != v[i].se) cnt++;
	}
	if((n==1 && m==1) || cnt==0){
		cout<<0<<endl;
		return;
	}
	if(n==1 || m==1){
		if(n==1){
			cout<<(2*m)<<endl;
			for(int i=1;i<=m;i++){
				cout<<"L";
			}
			for(int i=1;i<=m;i++){
				cout<<"R";
			}
			cout<<endl;
		}
		else{
			cout<<(2*n)<<endl;
			for(int i=1;i<=n;i++){
				cout<<"U";
			}
			for(int i=1;i<=n;i++){
				cout<<"D";
			}
			cout<<endl;
		}
		return;
	}
	if(n + m <= n*m){
	cout<<(n+m+n*m)<<endl;
	forn(j,n) cout<<"U";
	forn(j,m) cout<<"L";
	int b = 0;
	for(int i=0;i<m;i++){
		for(int j=1;j<n;j++){
			cout<<(b?"U":"D");
		}
		cout<<"R";
		b^=1;
	}
	cout<<endl;
	return;
}	
cout<<-1<<endl;
	return;
		
		
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

