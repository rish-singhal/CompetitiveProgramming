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
  	vector<int> v(n);
  	forn(i,n){
  		cin>>v[i];
  	}
  	sort(all(v));
  	int cnt = 1;
  	int cnt2 = 0;
  	forn(i,n){
  		if(v[i]!=v[i-1] && i>=1){
  			if((i)>=v[i-1]){
  				cnt2=i;
  			}
  		}
  	}
  	if((n)>=v[n-1] && n>=1){
  		cnt2 = n;
  	}
  	cout<<(cnt2+1)<<endl;
  }
  return 0;
}