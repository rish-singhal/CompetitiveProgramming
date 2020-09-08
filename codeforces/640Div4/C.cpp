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
  	LL n,k; cin>>n>>k;
  	LL ss = 0;
//   	for(LL i = n; ; i+=n){
//   		if(n-1>=k){
//   			cout<<(i-n+(k))<<endl;
//   			break;
//   		}
//   		k-=n-1;
//   		//cout<<k<<" -- "<<endl; 
//   	}
  	LL zz = k/(n-1);
  	LL mm = k%(n-1);
  	cout<<(zz*(n) + (mm==0?-1:mm))<<endl;
  }
  return 0;
}