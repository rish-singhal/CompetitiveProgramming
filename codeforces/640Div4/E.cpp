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
  int  t; cin>>t;
  while(t--){
  	LL n; cin>>n;
  	vector <LL> v(n), x;
  	forn(i,n) cin>>v[i];
  	x = v;
  	vector<LL> m(n+1);
  	for(auto i:x){
  		m[i]++;
  	}
  	for1(i,n-1) v[i]+=v[i-1];
  	int an =0;
  	for(int i=0;i<n;i++){
  		for(int j = i+1;j<n;j++){
  			LL su  = v[j]-(i>=1?v[i-1]:0);
  			if(su<=n && m[su]!=0){
  				an+=m[su];
  				m[su]=0;
  			}
  		}
  	}

  	//forn(i,n) if(m[x[i]]) an++;
  	cout<<an<<endl;
  }
  return 0;
}