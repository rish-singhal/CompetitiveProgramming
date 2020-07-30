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
  int n,k; cin>>n>>k;
  int inn = n - k;
  if(k >= (inn)){
  	int x = 2;
  	if(inn==1) cout<<2<<endl;
  	if(inn==2) cout<<3<<endl;
  	if(inn>=3) cout<<4<<endl;
  	forn(i,inn-1){
  		cout<<1<<" "<<(x++)<<endl;
  		cout<<(x-1)<<" "<<(x)<<endl;
  		x++;
  	}
  	forn(i, k-(inn-1))
  		cout<<1<<" "<<(x++)<<endl;
  	assert(x==n+1);
  }
  else{
  	inn--;
  	int in1 = (inn/(k));
  	int in2 = (inn/(k)) + (inn%(k));
  	int x = 2;
  	cout<<(in1+in2+2)<<endl;
  	forn(i,k-1){
  		int b = 1;
  		forn(j,in1+1){
  			cout<<b<<" "<<(x)<<endl;
  			b = (x++);
  		}
  	}
  	int b = 1;
  	forn(j,in2+1){
  		cout<<b<<" "<<(x)<<endl;
  		b = (x++);
  	}
  	assert(x==n+1);
  }
  return 0;
}