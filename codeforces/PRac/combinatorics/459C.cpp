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
  LL n,k,d; cin>>n>>k>>d;
  LL z = 1;
  forn(i,d){
  	z*=k;
  	if(z>=n) break;
  }
  if(z<n){
  	cout<<-1<<endl;
  	return 0;
  }
  vector<vector<int> > an(d, vector<int>(n));
  forn(i,n){
  	int p = i;
  	forn(j,d){
  		an[j][i] = (p%k) + 1;
  		p/=k;
  	}
  }
  for(int i=0;i<d;i++,cout<<endl)
  	forn(j,n) cout<<an[i][j]<<" ";
  return 0;
}