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

// sum = even, k = odd => even
// sum = odd, k = even => x
// sum = odd, k = odd=> odd
// sum = even, k = even => odd

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n,k ;cin>>n>>k;
  	int aa = n&1;
  	int kk = k&1;
  	vector<int> an;
  	if(aa && !kk){
  		cout<<"NO"<<endl;
  		continue;
  	}
  	if(!aa && kk){
  		if(n>=2*k){
  			int su = 0;
			cout<<"YES"<<endl;
  			forn(i,k-1){
  				su+=2;
  				an.pb(2);
  			}
  			an.pb(n-su);
  			for(auto i:an) cout<<i<<" ";
  				cout<<endl;
  			continue;
  		}
  		else{
  			cout<<"NO"<<endl;
  			continue;
  		}
  	}
  	if(n>=k){
  			int su = 0;
			cout<<"YES"<<endl;
  			forn(i,k-1){
  				su+=1;
  				an.pb(1);
  			}
  			an.pb(n-su);
  			for(auto i:an) cout<<i<<" ";
  				cout<<endl;
  			continue;

  	}
  	else{
  		cout<<"NO"<<endl;
  			continue;
  	}
  }
  return 0;
}