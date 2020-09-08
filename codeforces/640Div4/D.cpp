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
  	vector<LL> v(n);
  	forn(i,n){
  		cin>>v[i];
  	}
  	int l = 1, r = n-1;
  	LL a = v[0], b = 0;
  	int c = 1;
  	int m = 1;
  	vector <int> ch(n,0);
  	ch[0] = 1;
  	int bc = v[0];
  	//cout<<a<<" "<<b<<"---"<<endl;
  	while(l<=r){
  		if(m){
  			int xx = 0;
  			while(xx<=bc && ch[r]==0){
  				xx+=v[r];
  				ch[r] = 1;
  				r--;
  			}
  			b+=xx;
  			bc = xx;
  		}
  		else{
  			int xx = 0;
  			while(xx<=bc && ch[l]==0){
  				xx+=v[l];
  				ch[l] = 1;
  				l++;
  			}
  			a+=xx;
  			bc = xx;
  		}
  		c++;
  		m^=1;
  		//cout<<a<<" "<<b<<"---"<<endl;
  	}
  	//forn(i,n) cout<<ch[i]<<" ";
  	//cout<<endl;
  	cout<<c<<" "<<a<<" "<<b<<endl;
  }
  return 0;
}