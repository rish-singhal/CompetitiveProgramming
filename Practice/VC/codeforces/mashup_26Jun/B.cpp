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
  	set<int> s;
  	int an = 0;
  	for1(i,n) s.insert(i);
  	vector<int> v;
  	forn(i,n){
  		int k; cin>>k;
  		int b = 0;
  		forn(j,k){
  			int x; cin>>x;
  			if(b==0 && s.find(x)!=s.end()){
  				s.erase(x);
  				b = 1;
  			}
  		}
  		if(b==0) v.pb(i+1);
  	}
  	if(s.size() && v.size()){
  		cout<<"IMPROVE"<<endl;
  		cout<<(v[0])<<" "<<(*s.begin())<<endl;
  	}
  	else{
  		cout<<"OPTIMAL"<<endl;
  	}
  }
  return 0;
}