#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;
// check MAXN


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  LL n, k; cin>>n>>k;
  vector<LL> v(n);
  forn(i,n) cin>>v[i];
  multiset <LL> s;
  for(auto i:v){
  	s.insert(i);
  }
  
  while(s.size() < k){
  	LL val = *s.rbegin();
  	s.erase(s.find(val));
  	s.insert((val/2));
  	s.insert(((val + 1)/2));
  }

  LL su = 0;
  for(auto i:s) su += i*i;
  cout<<su<<endl;

  return 0;
}