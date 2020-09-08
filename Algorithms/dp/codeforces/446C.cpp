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
  vector<LL> v(n), p(n),s(n), cnt(n);
  LL sum =0;
  forn(i,n) {
  	cin>>v[i];
  	sum+=v[i];
  }
  if(sum%3!=0){
  	cout<<0<<endl;
  	return 0;
  }
  LL su = sum/3;
  vector<LL> l,r;
  forn(i,n) {
  	p[i] = v[i]+(i>=1?p[i-1]:0);
  	if(p[i]==su){
  		l.pb(i);
  	}
  }
  for(int i = n-1;i>=0;i--){
  	s[i] = v[i]+ (i+1<n?s[i+1]:0);
  	cnt[i] = (s[i]==su) + (i+1<n?cnt[i+1]:0);
  }
  LL an = 0;
  for(auto i:l){
  	an+= cnt[i+2];
  }
  cout<<an<<endl;
  return 0;
}