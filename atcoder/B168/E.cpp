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
const LL mm = 1e9 + 7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL po(LL a, LL b){
	if(b==0) return 1;
	LL an =po(a,b/2);
	an = (an*an)%mm;
	if(b&1) an = (an*a)%mm;
	return an;
}

int main(){
  fio();
  int n; cin>>n;
  map <pair<LL,LL>, LL> m;
  map <pair<LL,LL>, LL> vis;
  LL cnt = 0;
  LL cnta = 0; 
  LL cntb = 0;
  forn(i,n){
  	LL a, b; cin>>a>>b;
  	LL x = gcd(a,b);
  	if(x==0){
  		if(a==0 && b==0) {
  			cnt++;
  			continue;
  		}
  		if(a==0 && b!=0) cnta++;
  		if(b==0 && a!=0) cntb++;
  		continue;
  	}
  	a/=x, b/=x;
  	if(b<0){
  		b*=-1;
  		a*=-1;
  	}
  	m[{a,b}]++;
  } 
  LL an = 1;
  for(auto i:m){
  	 if(vis[i.fi]) continue;
     pair<LL,LL> zx = {-1*i.fi.se,i.fi.fi};
     if(zx.se<0){
       zx.fi*=-1;
       zx.se*=-1;
     }
     LL pp = 0;
     if(m.find(zx)==m.end()){
     	pp = 0;
     }
     else pp = m[zx];
 	 LL z = ((po(2,i.se)-1) + (po(2,pp) - 1) + 1 + mm)%mm; 
 	// cout<<z<<"--"<<endl;
     z = (z+mm)%mm;
 	 an = (an*z)%mm;
 	 vis[zx] = 1;
 	 vis[i.fi] = 1;
  }
  LL z = ((po(2,cnta)-1) + (po(2,cntb) - 1) + 1 + mm)%mm; 
  z = (z+mm)%mm;
  an = (an*z)%mm;
  an = (an + cnt - 1 + mm)%mm;
  cout<<an<<endl;
  return 0;
}

