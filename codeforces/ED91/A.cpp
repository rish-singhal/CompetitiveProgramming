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
  	int n; cin>>n;
  	vector<LL> v(n), b(n), f(n);	
  	forn(i,n){
  		cin>>v[i];
  		if(i==0){
  			b[i] = 0;
  		}
  		else{
  			if(v[i] < v[b[i-1]]){
  				b[i] = i;
  			}
  			else{
  				b[i] = b[i-1];
  			}
  		}
  	}
  	f[n-1] = n-1;
  	for(int i = n-2; i>=0; i--){
		if(v[i] < v[f[i+1]]){
  				b[i] = i;
  			}
  			else{
  				f[i] = f[i+1];
  		}
  	}
  	int bb = 0;
  	for(int i = 2; i < n-1; i++){
  		if(v[b[i-1]] < v[i] && v[i] > v[f[i+1]]){
  			cout<<"YES"<<endl;
  			cout<<b[i-1]+1<<" "<<i+1<<" "<<f[i+1]+1<<endl;
  			bb=1;
  			break;
  		}
  	}
  	if(!bb)cout<<"NO"<<endl;

  }
  return 0;
}