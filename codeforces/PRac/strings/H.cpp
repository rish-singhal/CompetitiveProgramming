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
  	int b = 0;
  	for(int i=1;i*i<=n;i++){
  		if(n%i==0){
  		  int len = i + (n/i) + 2;
  		  if(len<=100000){
  		  	string s(i,'1');
  		  	string p((n/i),'7');
  		  	forn(pp,i) cout<<1;
  		  	cout<<33;
  		  	forn(pp,(n/i)) cout<<7;
  		  	cout<<endl;
  		  	b = 1;
  		  	break;
  		  }
  		}
  	}
  	if(b==0){
  		forn(pp,n) cout<<1;
  		  	cout<<33;
  		forn(pp,1) cout<<7;
  		  	cout<<endl;
  	}
  }
  return 0;
}