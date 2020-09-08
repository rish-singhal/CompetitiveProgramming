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
  int t; cin>>t;
  while(t--){
  	LL l, r, m;
  	cin>>l>>r>>m;
  	LL lim = (r - l);
  	int an = 0;
  	for(LL a = l; a <= r; a++){
  		LL mm = m % a;
  		LL mp = a - mm;
  		if( mm <= lim && (mm!=m)){
  			cout<<a<<" "<<(l + mm)<<" "<<l<<endl;
  			an = 1; break;
  		}
  		if( mp <= lim && (-mm != m)){
  			cout<<a<<" "<<(l)<<" "<<(l+mp)<<endl;
  			an = 1; break;
  		}
  	}
  	if(an) continue;
  }
  return 0;
}