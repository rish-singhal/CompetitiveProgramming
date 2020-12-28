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
  int t; cin>>t;
  while(t--){
  	int n, k; cin>>n>>k;
  	vector <LL> h(n);
  	forn(i,n) cin>>h[i];
  	int mi = 0, ma = 0;
  	int b = 0;
  	forn(i,n - 1) 
  	{
  		if(i == 0){
  			mi = h[i];
  			ma = h[i];
  		}
  		else {
  			int mm = h[i];
  			int mx = h[i] + k - 1;
  			mi = max(mm, mi - k + 1);
  			ma = min(mx, ma + k - 1);
  			if(mi > ma){
  				b = 1;
  				break;
  			}
  		}
  		//cout << mi <<" " << ma << endl;
  	}
  	if(b){
  		cout << "NO" << endl;
  		continue;
  	}

  	if( ma >= mi && h[n-1] >= mi - k + 1 && h[n-1] <= ma + k - 1)
  	{
  		cout<<"YES"<<endl;
  	}
  	else cout << "NO" << endl;
  }
  return 0;
}
