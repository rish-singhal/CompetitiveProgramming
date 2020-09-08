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
  LL n,k,p; cin>>n>>k>>p;
  while(p--){
  	LL z; cin>>z;
  	if(k==0){
  		cout<<".";
  		continue;
  	}
  	if(z==n || k>=n){
  		cout<<"X";
  		continue;
  	}
  	if(((k-(n&1)))<=(n/2)){
  		if(z%2!=0){
  			cout<<".";
  		}
  		else{
  			if((n - (n&1) -z)/2 < (k-(n&1))){
  				cout<<"X";
  			}
  			else{
  				cout<<".";
  			}
  		}
  		continue;
  	}
  	if((k-(n&1))>(n/2)){
  		//cout<<"32434"<<endl;
  		if(z%2==0){
  			cout<<"X";
  			continue;
  		}
  		LL pp = (n - (n&1)-z)/2;
  		LL kk = (k-(n&1)) - (n/2);
  		//cout<<pp<<" "<<kk<<endl;
  		if(pp < kk){
  			cout<<"X";
  		}
  		else cout<<".";
  		continue;
  	}


  }
  return 0;
}