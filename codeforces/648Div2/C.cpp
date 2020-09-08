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
  vector<int> a(n), b(n);
  forn(i,n) {
  	LL x; cin>>x;
  	x--;
  	a[x] = i;
  }
  //map<LL, LL> m;
  vector<LL> x(n);
  forn(i,n){
  	cin>>b[i];
  	b[i]--;
  	int in = (a[b[i]] - i+n)%n;
  	x[in]++;
  }
  cout<<(*max_element(all(x)))<<endl;
  return 0;
}