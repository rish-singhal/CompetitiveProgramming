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
// check MAXN

// b*m > a
// b/a > m

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
  	vector<LL> v(n);
  	forn(i,n) cin>>v[i];
  	vector<LL> ss(n);
  	forn(i,n-1){
  		if(v[i] > v[i+1]){
  			ss[i] = v[i] - v[i+1];
  		}
  	}
  	for(int i = n-2; i >= 0 ; i--){
  		ss[i] += ss[i+1];
  	}
  	int b = 1;
  	for(int i = 0; i < n -1 ;i ++){
  		b&= (ss[i] <= v[i]);
  	}
  	cout<<(b?"YES":"NO")<<endl;
  }
  return 0;
}