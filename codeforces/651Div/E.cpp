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
  vector<int> v;
  string s,b; cin>>s>>b;
  int cnt0 = 0, cnt1=0 ;
  forn(i,n){
  	if(s[i]!=b[i]){
  		v.pb(s[i]);
  		cnt0+=(s[i]=='0');
  		cnt1+=(s[i]=='1');
  	} 	
  }
  if(cnt0!=cnt1){
  	cout<<-1<<endl;
  	return 0;
  }
  cnt0 = 0 , cnt1 = 0;
  forn(i,v.size()){
  	if(v[i]=='0'){
  		if(cnt1==0){
  			cnt0++;
  		}
  		else{
  			cnt1--;
  			cnt0++;
  		}
  	}
  	else{
  		if(cnt0==0){
  			cnt1++;
  		}
  		else{
  			cnt1++;
  			cnt0--;
  		}
  	}
  }
  cout<<(cnt1+cnt0)<<endl;
  return 0;
}