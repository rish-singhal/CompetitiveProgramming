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
  	int n,k ;cin>>n>>k;
  	string s; cin>>s;
  	int b = -1;
  	LL an =0;
  	forn(i,s.size()){
  		if(s[i]=='1'){
  			int len = i-b-1;
  			if(b==-1) len = max(len-k,0);
  			else len = max(len-2*k,0);
  			if(len!=0)an+= ((len+k)/(k+1));

  			b = i;
  		}
  	}
  	int len = n-b-1;
  //	cout<<len<<endl;
	if(b==-1) len = max(len,0);
  	else len = max(len-k,0);
  	//cout<<len<<endl;
  	if(len!=0)an+=((len+k)/(k+1));
  	cout<<an<<endl;
  }
  return 0;
}