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
  LL x; cin>>x;
  for(LL i=1;i*i<=x; i++){
  	if(x%i==0){
  		for(LL b = -1e5; b<=1e5;b++){
  			LL a = b+i;
  			LL z = a*a*a*a*a - b*b*b*b*b;
  			if(z==x){
  				cout<<a<<" "<<b<<endl;
  				return 0;
  			}
  		}
  	}
  }
  for(LL i=1;i*i<=x; i++){
  	if(x%i==0){
  		for(LL a = -1e5; a<=1e5;a++){
  			LL b = a-i;
  			LL z = a*a*a*a*a - b*b*b*b*b;
  			if(z==x){
  				cout<<a<<" "<<b<<endl;
  				return 0;
  			}
  		}
  	}
  }
  return 0;
}