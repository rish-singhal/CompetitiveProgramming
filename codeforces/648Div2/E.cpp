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
  LL n; cin>>n;
  vector<LL> v(n);
//  vector<vector<LL>> vv(n, vector<LL>(60,0));
  LL an = 0 ;
  forn(i,n){
  	cin>>v[i];
  	an = max(an, v[i]);
  }

  forn(i,n){
  	for(int j =i+1;j<n;j++){
  		LL va = v[i] | v[j];
  		an = max(an,va);
  	}
  }

   forn(i,n){
  	for(int j =i+1;j<n;j++){
  	 for(int k = j+1;k<n;k++){
  		LL va = v[i]|v[j]|v[k];
  		an = max(an,va);
  		}
  	}
  }
  cout<<an<<endl;
  return 0;
}