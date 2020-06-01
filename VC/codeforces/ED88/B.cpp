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
  int t; cin>>t;
  while(t--){
  	LL n,m,x,y; cin>>n>>m>>x>>y;
  	y = min(y,2*x);
  	vector<string> s(n);
  	forn(i,n) cin>>s[i];
  	LL an = 0;
  	forn(i,n){
  		int cnt = 0;
  		forn(j,m){
  			if(s[i][j]=='.'){
  				cnt++;
  			}
  			else{
  				an+=(cnt/2)*y + (cnt&1?x:0);
  				cnt = 0;
  			}
  		}
  		if(cnt){
  			an+=(cnt/2)*y + (cnt&1?x:0);
  			cnt = 0;
  		}
  	}
  cout<<an<<endl;
}
  return 0;
}