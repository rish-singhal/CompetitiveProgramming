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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<int> v(n);
  	forn(i,n) cin>>v[i];
  	sort(all(v));
  	if(n==1){
  		if(v[0]<=0){
  			cout<<"NO"<<endl;
  			continue;
  		}
  	}
  	if(v[1]<=0){
  		int jj = -1;
  		for(int i=0;i<n;i++){
  			if(v[i]>0){
  				jj = i;
  				break;
  			}
  		}
  		if(jj==-1){
  			cout<<"NO"<<endl;
  			continue;
  		}
  		vector<int> vv(n);
  		vv[0] = v[0];
  		vv[1] = v[jj];
  		for(int i=2; i<=jj; i++){
  			vv[i] = v[i-1];
  		}
  		for(int i = jj+1; i<n; i++)
  			vv[i] = v[i];
  		v = vv;
  	}
  	if(v[1]<=0 && n>1){
  		cout<<"NO"<<endl;
  		continue;
  	}
  	
  	vector<LL> an(n);
  	//cout<<"YES"<<endl;
  	for(int i=0;(i+1)<n;i+=2){
  		an[i] = v[i+1];
  		an[i+1] = v[i];
  	}
  	if(n&1) an[n-1] = v[n-1];
  	int f = 0;
  	forn(i,n-1){
  		if(abs(an[i]-an[i+1])==0){
  			f = 1;
  			cout<<"NO"<<endl;
  			break;
  		}
  	}
  	if(f) continue;
  	cout<<"YES"<<endl;
  	for(auto i:an) cout<<i<<" ";
  	cout<<endl;
  }
  return 0;
}