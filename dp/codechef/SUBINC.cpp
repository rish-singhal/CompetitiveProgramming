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
  	int n; cin>>n;
  	LL c = 1;
  	LL an = 0;
  	int b;
  	forn(i,n){
  		int x; cin>>x;
  		if(i==0) an+=c;
  		else{
  			if(x>=b) c++;
  			else c = 1;
  			an+=c;
  		}
  		b = x;
  	}
  	cout<<an<<endl;
  }
  return 0;
}