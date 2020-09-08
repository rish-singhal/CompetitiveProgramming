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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin>>n;
  vector<LL> v(n);
  vector<LL> ev(n), od(n);
  forn(i,n){
  	LL x; cin>>x;
  	if(!(i&1))	{
  		ev[i] += x + (i>=1?ev[i-1]:0);
  		od[i] = (i>=1?od[i-1]:0);
  	}
  	else{
		od[i] += x + (i>=1?od[i-1]:0);
  		ev[i] = (i>=1?ev[i-1]:0);
  	}
  }
  LL ma = ev[n-1];

  for1(i,n-1){
  	LL ann = 0;
  	if((i&1) && i>=1){
  		ann = ev[i] + (od[n-1]-od[i-1]); 
  	}
  	else if(i>=1 && (i%2==0)){
  		ann = od[i] + (ev[n-1] - ev[i-1]);
  	}	
  	ma = max(ma, ann);
  }
  cout<<ma<<endl;
  return 0;
}