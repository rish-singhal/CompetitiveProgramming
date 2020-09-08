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
  	LL a,b; cin>>a>>b;
  	if(a>b) swap(a,b);
  	if(a==b){
  		cout<<0<<endl;
  		continue;
  	}
  	if(b%a!=0){
  		cout<<-1<<endl;
  		continue;
  	}
  	int an = 0;
  	while(a<b){
  		if(a*8<=b) a*=8;
  		else if(a*4<=b) a*=4;
  		else if(a*2<=b) a*=2;
  		else break;
  		an++;

  	}
  	if(a==b){
  		cout<<an<<endl;
  	}
  	else cout<<-1<<endl;
  }
  return 0;
}