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
  	int n,m ;cin>>n>>m;
  	if(n%2==0){
  		int k = 1;
  		forn(i,n){
  			forn(j,m){
  				if(j==0 && i==1) cout<<"B";
  				else cout<<(k?"B":"W");
  			}
  			k^=1;
  			cout<<endl;
  		}
  		continue;
  	}
  	if(m%2==0){
  		int k = 1;
  		forn(i,n){
  			forn(j,m){
  				if(j==1 && i==0) cout<<"B";
  				else cout<<(k?"B":"W");
  				k^=1;
  			}
  			cout<<endl;
  		}
  		continue;
  	}
  	int  k = 1;
  	forn(i,n){
  		forn(j,m){
				cout<<(k?"B":"W");
  				k^=1;
  		}
  		cout<<endl;
  	}
  }
  return 0;
}