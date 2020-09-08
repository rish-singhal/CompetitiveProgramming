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
  LL x,n; cin>>x>>n;
  vector<LL> v(n);
  set<int> s;
  forn(i,n){
  	cin>>v[i];
  	s.insert(v[i]);
  }
  LL dis = 0;
  while(1){
  	if(s.count(-dis+x)==0){
  		cout<<-dis+x<<endl;
  		return 0;
  	}
  	if(s.count(dis+x)==0){
  		cout<<dis+x<<endl;
  		return 0;
  	}
  	dis++;
  }
  return 0;
}