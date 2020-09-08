#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i= 0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

typedef long long LL;
const LL m =1e9 +7;

void solve(){
	int n; cin>>n;
	vector <int> v[n];
	forn(i,n){
		int k; cin>>k;
		forn(j,k){
			int z; cin>>z;
			z--;
			v[i].pb(z);
		}
	}
	vector <int> b(n,0);
	vector <int> an(n,-1);
	vector <int> vv;
	forn(i,n){
		int bb = 0;
		for(auto j:v[i]){
			if(b[j]==0){
				an[i] = j;
				b[j] = bb= 1;
				break;
			}
		}
		if(bb==0) vv.pb(i);
	}
	if(vv.size()==0){
		cout<<"OPTIMAL\n";
		return;
	}
	cout<<"IMPROVE\n";
	forn(j,n){
		if(b[j]==0){
			cout<<(vv[0]+1)<<" "<<(j+1)<<endl;
			break;
		}
	}
	return;
		
	
		
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

