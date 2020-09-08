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
  int n; cin>>n;
  int x = 0;
  int m = -1;
  int len = 1e9;
  while(4*x<=n){
  	if((n-(4*x))%7==0){
  		LL z =(n-(4*x))/7; 
  		if(len > z+x){
  			m = x;
  			len = z+x;
  		}
  	}
  	x++;
  } 
  if(m==-1) {cout<<-1<<endl; return 0;
  }
  forn(i,m) cout<<4;
  LL z = (n-(4*m))/7;
  forn(i,z) cout<<7;
  cout<<endl;
  return 0;
}