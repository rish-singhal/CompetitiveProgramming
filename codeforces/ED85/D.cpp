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
  	LL n,l,r;
  	cin>>n>>l>>r;
  	l--,r--;
  	LL p = 1;
  	LL su = 2*(n-1);
  	if(n*(n-1)==l){
  		cout<<1<<endl;
  		continue;
  	}
  	while(p<=n){
  		if(su>=l) break;
  		p++;
  		su+=2*(n-p);
  		//cout<<su<<" --- "<<endl;
  	}
  	su-=2*(n-p);
  	// p--;
  	//cout<<"p: "<<p<<endl;
  	//cout<<"su :"<<su<<endl;
  	LL ss = su;
  	vector<LL> v;
  	while(1){
  		int z = 1;
  		for(int i=p+1;i<=n;i++){
  			su++;
  			if(su>l && su<=r+1) {
  				cout<<p<<" ";}
  			su++;
  			if(su>l && su<=r+1){
  				cout<<i<<" ";
  			} 
  			if(su>r+1) {
  				z = 0;
  				break;
  			}
  		}
  		p++;
  		if(!z) break;
  		if(su>r+1) break;
  		if(p==n){
  			su++;
  			if(su<=r+1 && su>l) cout<<1;
  			break;
  		}
  	}
  	//cout<<p<<" --- "<<endl;
  	cout<<endl;
  }
  return 0;
}