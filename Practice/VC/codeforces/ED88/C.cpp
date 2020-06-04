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
  	LL h,c,t; cin>>h>>c>>t;
  	if(2*t <= h+c){
  		cout<<2<<endl;
  		continue;
  	}
  	LL X = (LL)((h-t)/(2*t-h-c));	
  	//double z = (double)((double)(X+1)*h+X*c)/(2*X+1);
  	pair<LL,LL> z = {abs((2*X+1)*t - ((X+1)*h+X*c)), 2*X + 1};
  	//cout<<z<<endl;
  	LL an = X;
  	//cout<<X<<endl;
  	for(LL p = max(0LL,(X+1000)); p >= max(0LL,X-1000);p--){
  		pair<LL,LL> pz = {abs((2*p+1)*t - ((p+1)*h+p*c)), 2*p + 1};
  		if((LL)z.fi*pz.se >= z.se*pz.fi){
  			z = pz;
  			an = p;
  		}
  	}	
  	if((h+c)*z.se <= 2*z.fi){
  		an = 2;
  	}
  	cout<<(2*an+1)<<endl;
  }
  return 0;
}