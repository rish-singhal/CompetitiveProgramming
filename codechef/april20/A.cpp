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

void solve(){
	LL x,k; cin>>x>>k;
	LL cnt =0;
	for(int i =2;i*i<=x;i++){
		while(x%i==0){
			cnt++;
			x/=i;
		}
	}
	if(x>1) cnt++;
	cout<<(cnt>=k?1:0)<<endl;
}

int main(){
  fio();
  int t;cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}