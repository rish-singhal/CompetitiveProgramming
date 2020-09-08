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
  	int n; cin>>n;
  	n--;
  	int d = 0;
  	int x = 1;
  	vector<int> an;
  	while(n>0){
  	//	cout<<n<<endl;
  		if(n>=x && n<=2*x){
  			an.pb(n-x);
  			break;
  		}
  		else{
  			int z = max(x, min(2*x, (n/2)));
  			an.pb(z-x);
  			x = z;
  			n-=x;
  		}
  	}
  	cout<<an.size()<<endl;
  	for(auto i:an) cout<<i<<" ";
  		cout<<endl;
  }
  return 0;
}