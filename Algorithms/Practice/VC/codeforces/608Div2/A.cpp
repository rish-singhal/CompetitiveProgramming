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

/*
WWWWWWW
BWWWW

0001000010010001

*/

int main(){
  fio();
  int n; cin>>n;
  string s; cin>>s;
  vector<int> ss;
  int cnt = 0 ;
  for(auto &i:s){
  	if(i=='W') i = 'A';
  }
  forn(i,n){
  	cnt+= s[i]-'A';
  	ss.pb(s[i]-'A');
  }
  int x = -1;
  if((cnt&1) == 0){
  	x = 1;
  }
  else if(((n-cnt)&1)==0){
  	x = 0;
  }
  else {
  	cout<<-1<<endl;
  	return 0;
  }
  vector<int> an;
  forn(i,n-1){
  	if(ss[i]==x && ss[i+1]==x){
  		ss[i]^=1, ss[i+1]^=1;
  		an.pb(i);
  	}
  }
  forn(i,n-1){
  	if(ss[i]==x && ss[i+1]==x){
  		ss[i]^=1, ss[i+1]^=1;
  		an.pb(i);
  	}
  }
  vector<int> vv;
  forn(i,n){
  	if(ss[i]==x) vv.pb(i);
  }
  assert((vv.size()&1) == 0);
  forn(i,vv.size()){
  	if(i&1) continue;
  	for(int k = vv[i]; k<vv[i+1];k++)
  			an.pb(k);
  }
  cout<<an.size()<<endl;
  assert(an.size()<=3*n);
  for(auto i:an) cout<<i+1<<" ";
  	cout<<endl;
  return 0;
}