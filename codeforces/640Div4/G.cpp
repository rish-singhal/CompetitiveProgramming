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
const int MAXN = 1e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// 2, 4, 1, [ 5 , 7 , 3 , 6 ] 

void test(int n){
	if(n<4){
	 cout<<-1<<endl;
	 return;
	}
	vector<int> an;
	for(int k=0;k+4<=n;k+=4){
		an.pb(k+2);
		an.pb(k+4);
		an.pb(k+1);
		an.pb(k+3);
	}

	if(n%4==1){
		an.pb(n);
	}
	else if(n%4==2){
		int k = an.back();
		an.pop_back();
		an.pb(n-1);
		an.pb(k);
		an.pb(n);
	}
	else if(n%4==3){
		int k = an.back();
		an.pop_back();
		an.pb(n-2);
		an.pb(n);
		an.pb(k);
		an.pb(n-1);
		
	}
	for(auto i:an) cout<<i<<" ";
	cout<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n ;cin>>n;
  	test(n);
  }
  return 0;
}