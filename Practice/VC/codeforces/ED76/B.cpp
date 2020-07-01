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

// 6 -> 9-> 8, 12, 

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL x, y; cin>>x>>y;
  	if(y<=x){	
  		cout<<"Yes"<<endl;
  		continue;
  	}
  	if(x==1){
  		cout<<(y==1?"Yes":"No")<<endl;
  		continue;
  	}
  	if(x==2 || x==3){
  		if(y<=3) cout<<"Yes"<<endl;
  		else cout<<"No"<<endl;
  		continue;
  	}
  	cout<<"Yes"<<endl;
  }
  return 0;
}