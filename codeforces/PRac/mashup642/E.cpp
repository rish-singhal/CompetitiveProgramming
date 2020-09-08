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
const int MAXN = 4e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL cnt[MAXN];
set <int> s[MAXN];

int main(){
  fio();
  LL q,x; cin>>q>>x;
  LL nem = 0;
  forn(i,x) s[0].insert(i);
  while(q--){
  	LL z; cin>>z;
  	z %= x;
  	s[cnt[z]].erase(z);
  	if(s[nem].size()==0){
  		nem++;
  	}
  	cnt[z]++;
  	s[cnt[z]].insert(z);
  	cout<<(*s[nem].begin() + nem*x)<<endl;
  }
  return 0;
}