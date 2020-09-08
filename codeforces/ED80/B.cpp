#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL m =1e9 +7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin>>t;
	while(t--){
		LL a,b; cin>>a>>b;
		LL kk = 9999999999;
		LL c= 0 ;
		while(kk>0){
			if(b>=kk) c++;
			kk/=10;
		}
		cout<<(a*c)<<endl;
	}
	
	return 0;
}
