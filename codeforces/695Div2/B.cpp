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
const int MAXN = 5e5 +5;
const LL mm = 1e9 + 7;
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
  	int n; cin>>n;
  	vector<LL> a(n);
  	forn(i,n) cin>>a[i];
  	int ans = 0;
  	int b = 0, c = 0;
  	for(int i = 1; i < (n-1); i++)
  	{
  		if(a[i] > a[i+1] && a[i] > a[i-1])
  			ans++;
  		if(a[i] < a[i+1] && a[i] < a[i-1])
  			ans++;

  		if(a[i] > a[i+1] && a[i] > a[i-1])
  			{
  				if(i-2>=0 && a[i-2] > a[i-1] && i+2 < n && a[i+2] > a[i+1])
  					c = 1;
  				else if(i+2 < n && a[i+2] > a[i+1] && i-2 >= 0 && a[i-2] == a[i-1] && a[i-1] < a[i + 1])
  					b = 1;
  				else if(i-2 >= 0 && a[i-2] > a[i-1] && i+2 < n && a[i+2] == a[i+1] && a[i-1] > a[i + 1])
  					b = 1;
  				// if(a[i+1] == a[i-1])
  				// 	b = 1;
  				// else 
  					//c = 1;
  			}

  		if(a[i] < a[i+1] && a[i] < a[i-1] && i-2>=0 && a[i-2] < a[i-1] && i+2 < n && a[i+2] < a[i+1] )
  			{
  				// if(a[i+1] == a[i-1])
  				// 	b = 1;
  				// else 
  				if(i-2>=0 && a[i-2] < a[i-1] && i+2 < n && a[i+2] < a[i+1] )
  					c = 1;
  				else if(i+2 < n && a[i+2] < a[i+1] && i-2 >= 0 && a[i-2] == a[i-1] && a[i-1] > a[i + 1])
  					b = 1;
  				else if(i-2>=0 && a[i-2] < a[i-1] && i+2 < n && a[i+2] == a[i+1] && a[i-1] < a[i + 1])
  					b = 1;
  			}

  	}
  	//cout << ans << " ";
  	if(c) ans -= 3;
  	else if(b) ans -= 2;
  	else ans -= 1;
  	cout << max(0, ans) << endl;
  }
  return 0;
}
