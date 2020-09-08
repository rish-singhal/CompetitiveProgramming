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
  LL n; cin>>n;
  vector<LL> v(n);
  LL su = 0;
  map<LL,LL> m;
  forn(i,n) {
  	cin>>v[i];
  	su+=v[i];
  	m[v[i]]++;
  }
  LL q;cin>>q;
  while(q--){
  	LL b,c; cin>>b>>c;
  	su-=m[b]*(b-c);
  	m[c] += m[b];
  	m[b] = 0;
  	cout<<su<<endl;
  }
  return 0;
}