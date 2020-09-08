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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int ann[MAXN];

int main(){
  fio();
  int  n; cin>>n;
  vector<LL> v(n);

  forn(i,n-1){
   cin>>v[i];
   ann[v[i]]++;
	}	
	for1(i,n) cout<<ann[i]<<endl;
  return 0;
}