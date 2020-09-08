#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

void solve(){
	cout<<setprecision(7);
	cout<<fixed;
	double n; cin>>n;
	double p; cin>>p;
	double q = 1 - p;
	for(int i = 1; i <= n; i++){
		double an = 1.0;
		double prev = 1.0;
		for(int j = 2; j <= (n-1); j++){
			double zz= (n>=2?(n - 2)/n:0.0) + ((n >= j - 1 && i>(j-1))?(((double)i - (j - 1)) * p)/(n - (j-1)) : 0);
			zz += (n > (i-j + 2) && n > (j-1)?((n - i - (j - 2)) * q)/(n - (j-1)) :0 );
			prev *= zz;
			an += (double)j * prev;
		}
		cout<<an<<endl;
	}
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t){
  	cout<<"Case #"<<i<<": "<<endl;
  	solve();
  }
  return 0;
}