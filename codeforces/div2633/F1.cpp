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
  set<LL> s;
  vector<LL> v;
  for1(i,n){
  	if(s.count(i)) continue;
  	for(LL j = i+1;j<=n;j++){
  		LL z = 0;
  		if(s.count(j)) continue;
  		for(LL k = j+1;k<=n;k++){
  			if(s.count(k)) continue;
  			if((j^k^i)==0){
  				s.insert(i);
  				v.pb(i);
  				s.insert(j);
  				v.pb(j);
  				s.insert(k);
  				v.pb(k);
  				z = 1;
  				break;
  			}
  		}
  		if(z) break;
  	}
  }
  int cnt = 0;
  for(auto i:v) 
  	{
  		if(cnt==0) cout<<"\n";
  		cout<<i<<" ";
  		cnt = (cnt+1)%3;
}
  	cout<<endl;
  return 0;
}