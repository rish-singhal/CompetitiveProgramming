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
  int n,k; cin>>n>>k;
  vector<pair<int,int>> v;
  vector<int> vv(k), cnt(k,0);
  int x = 2;
  forn(i,k){
  	v.pb({1,x});
  	vv[i] = x;
  	cnt[i]++;
  	x++;
  }
  forn(i, (n-1-k)){
  	int z = i%k;
  	v.pb({vv[z], x});
  	vv[z] = x;
  	cnt[z]++;
  	x++;
  }
  sort(cnt.rbegin(), cnt.rend());
  cout<<(cnt[0]+cnt[1])<<endl;
  for(auto i: v)
  	cout<<i.fi<<" "<<i.se<<endl;
  return 0;
}