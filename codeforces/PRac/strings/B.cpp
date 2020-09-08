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
const LL mm = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin>>n;
  string s; cin>>s;
  	LL l = 0;
  	while(s[l]==s[0]) l++;
  	LL r = n-1;
  	while(s[r]==s[n-1]) r--;
  	if(l<=r){
  		//cout<<l<<" "<<(n-r)<<endl;
  	    if(s[0]==s[n-1]){
  		LL an = ((l+1)*(n-r))%mm;
  		cout<<an<<endl;
  		}	
  		else{
  		LL an = ((n-r)+(l))%mm;
  		cout<<an<<endl;
  		}
  	}
  	else if(l!=n-1 || r!=0){
  		LL an = ((n-r)+(l))%mm;
  		cout<<an<<endl;
  	}
  	else{
  		LL an = (n*(n+1))/2;
  		an = an%mm;
  		cout<<an<<endl;
  	}
  return 0;	
}