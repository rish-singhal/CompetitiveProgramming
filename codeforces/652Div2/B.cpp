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

// 11110000100   1111

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	string s; cin>>s;
  	reverse(all(s));
  	int cnt1 = 0, cnt2 =0, b = 0;
  	for(auto i:s){
  		if(i=='1') {
  			cnt1++;
  		}
  		else break;
  	}
  	reverse(all(s));
  	forn(i,n){
  		if(s[i]=='0')cnt2++;
  			else break;
  	}
  	forn(i,cnt2) cout<<"0";
  	if(cnt1+cnt2!=n) cout<<"0";
  	forn(i,cnt1) cout<<"1";
  	cout<<endl;

  }
  return 0;
}