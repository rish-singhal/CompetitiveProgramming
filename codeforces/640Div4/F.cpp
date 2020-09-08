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
  	vector <int> n(3);
  	forn(i,3) cin>>n[i];
  	if(n[1]==0 && n[2]==0){
  		forn(i,n[0]+1){
  			cout<<0;
  		}
  		cout<<endl;
  		continue;
  	}
  	if(n[1]==0 && n[0]==0){
  		forn(i,n[2]+1){
  			cout<<1;
  		}
  		cout<<endl;
  		continue;
  	}
  	if(n[1]==1){
  		forn(i,n[2]+1){
  			cout<<1;
  		}
  		forn(i,n[0]+1){
  			cout<<0;
  		}
  		cout<<endl;
  		continue;
  	}
  	if(n[1]>1){
  		int c=0;
  		int bb = 0;
  		cout<<0;
  		while((c+1)<n[1]){
  			cout<<(bb^1);
  			c++;
  			bb^=1;
  		}
  		if(bb==0){
  			forn(i,n[0]){
	  			cout<<0;
	  		}
  			forn(i,n[2]+1){
  				cout<<1;
  			}
  		}
  		else{
  			forn(i,n[2]){
  				cout<<1;
  			}
  			forn(i,n[0]+1){
	  			cout<<0;
	  		}
  		}
  		cout<<endl;
  		continue;
  	}
  }
  return 0;
}