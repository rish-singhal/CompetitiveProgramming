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
  vector<LL> v(n);
  forn(i,n) cin>>v[i];
  LL an = 0;
  LL su = 0;
  for(LL z = 30; z>=-30;z--){
  	LL p = 0;
  	for(int i=0;i<n;i++){
  		if(v[i]>z){
  			p = 0;
  		}
  		else{
  			p = max(p+v[i],v[i]);
  			su = max(su,p-z);
  		}
  	}
  }
  cout<<su<<endl;
  return 0;
}