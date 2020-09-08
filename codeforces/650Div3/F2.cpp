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
  	int n; cin>>n;
  	vector<LL> v(n);
  	LL mi = -1;
  	LL an1=0;
  	forn(i,n){
  		cin>>v[i];
  		if(v[i]>=mi){
  			mi = v[i];
  			an1++;
  		}
  	}
  	reverse(all(v));
  	LL ma = 1e17;
  	LL an2 = 0;
  	forn(i,n){
		if(v[i]<=ma){
  			ma = v[i];
  			an2++;
  		}
  	}
  	cout<<(n-max(an1,an2))<<endl;
  }
  return 0;
}