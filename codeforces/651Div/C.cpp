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
  	LL n; cin>>n;
  	if(n==1){
  		cout<<"FastestFinger"<<endl;
  		continue;
  	}
  	if(n==2){
  		cout<<"Ashishgup"<<endl;
  		continue;
  	}
  	if(n&1){
  		cout<<"Ashishgup"<<endl;
  		continue;
  	}
  	if(__builtin_popcountll(n)==1){
  		cout<<"FastestFinger"<<endl;
  		continue;
  	}
  	if( n%4==0 ){
  		cout<<"Ashishgup"<<endl;
  		continue;
  	}
  	LL k = n;
  	int cnt =0;
  	for(LL i=2; i*i<=n; i++){
  		if(n%i==0){
  			while((n%i)==0){
  				if(i!=2)cnt++;
  				n/=i;
  			}
  		}
  	}
  	if(n!=1) cnt++;
  	if(cnt>=2){
  		cout<<"Ashishgup"<<endl;
  	}
  	else {
  		cout<<"FastestFinger"<<endl;
  	}

  }
  return 0;
}