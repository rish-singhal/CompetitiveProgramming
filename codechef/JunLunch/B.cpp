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

void solve(){
	int n; cin>>n;
	double an1 = 0, an2 = 0;
	forn(i,n) {
		double g,a,b; cin>>g>>a>>b;
		an1 += (g*b)/(a+b);
		an2 += (g*a)/(a+b);
	}
	cout<<setprecision(10);
	cout<<fixed;
	cout<<an1<<" "<<an2<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}