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
  vector<LL> z(20);
  forn(i,n){
  	cin>>v[i];
  	forn(j,20){
  		if(v[i]&(1LL<<j)){
  			z[j]++;
  		}
  	}
  }
  LL an = 0;
  forn(i,n){
  	LL xx = 0;
  	forn(j,20){
  		if(z[j]){
  			xx+=1LL<<j;
  			z[j]--;
  		}
  	}
  	an+=xx*xx;
  }
  cout<<an<<endl;
  return 0;
}