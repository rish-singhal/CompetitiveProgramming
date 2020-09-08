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
  int t; cin>>t;
  while(t--){
  	LL n,x; cin>>n>>x;
  	vector <LL> v(n);
  	forn(i,n) cin>>v[i];
  	sort(v.begin(),v.end());
  	reverse(v.begin(),v.end());
  	LL sum = 0;
  	LL an = 0;
  	forn(i,n){
  		sum+=v[i];
  		if(sum >= x*(i+1)){
  			an = i+1;
  		}
  		else break;
  		//cout<<sum<<" ---- \n";
  	}
  	cout<<(an)<<endl;
  }
  return 0;
}