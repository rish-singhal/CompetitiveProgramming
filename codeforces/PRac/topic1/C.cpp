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
  int k; cin>>k;
  string s; cin>>s;
  int n =s.size();
  vector<int> v(n);
  forn(i,n) v[i] = s[i]-'0';
  for1(i,n-1) v[i]+=v[i-1];
  LL an =0;
  forn(i,n){
  	auto a = upper_bound(v.begin()+i+1, v.end(),k+v[i]);
  	auto b = lower_bound(v.begin()+i+1, v.end(),k+v[i]);
  	if(a==v.end() && b==v.end()) continue;
  	auto z = a- b;
  	//cout<<z<<endl;
  	an+=(LL)z;
  }
  an+=(LL)(upper_bound(all(v),k) - lower_bound(all(v),k));
  cout<<an<<endl;
  return 0;
}