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
  set<LL> s;
  forn(i,n){
  	forn(j,n){
  		s.insert(abs(i*i-j*j));
  		
  	}
  }
  forn(i,1000){
  	if(s.count(i)==0) cout<<(i)<<" ";
  }
  cout<<endl;
  return 0;
}

