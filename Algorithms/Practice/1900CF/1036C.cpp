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

LL dpx[20][2][4];

LL dp(int in, int f, int cnt, string s){
	if(in==s.size())
		return cnt<=3;
	LL &an = dpx[in][f][cnt];
	if(an!=-1) return an;
	int d = s[in]-'0';
	an = 0;
	forn(i,10){
	  if((f || i<=d) && cnt+min(i,1)<=3 )	
		an += dp(in+1, (f || (i<d)), cnt+min(i,1), s);
	}
	return an;
}


void solve(){
	LL x,y; cin>>x>>y;
	memset(dpx,-1,sizeof dpx);
	LL an1 = dp(0,0,0,to_string(y));
	memset(dpx,-1,sizeof dpx);
	LL an2 = dp(0,0,0,to_string(x-1));
	cout<<an1-an2<<endl;
}
int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}