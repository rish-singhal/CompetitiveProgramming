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
  string s; cin>>s;
  reverse(all(s));
  map<LL,LL> c;
  LL k = 1;
  LL z = 0;
  c[z]++;
  for(auto i:s){
  	z  = (z + (i-'0')*k)%2019;
  	k = k*10%2019;
  	c[z]++;
  }
  LL an = 0;
  for(auto i:c)
  	an += i.se*(i.se-1)/2;
  cout<<an<<endl;

  return 0;
}

