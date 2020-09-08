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
	LL n, d; cin>>n>>d;
	if(d<=n) cout<<"Yes\n"<<endl;
	else{
		int b = 0;
		for(LL i = 1; i*i<=d, i<=n;i++){
			if(((i)+((d+i)/(i+1))) <=n)
				{
					b = 1;
					break;
			}
		}
		cout<<(b?"Yes\n":"No\n");
	}
}
	return 0;
}

