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
  	vector<int> v(n);
  	multiset<int> s;
  	//vector<int> cnt(1024);
  	forn(i,n) {
  		cin>>v[i];
  		s.insert(v[i]);
  	}
  	int b = 0;
  	for1(k,1024){
  		multiset<int> ss;
  		forn(j,n){
  			ss.insert(v[j]^k);
  		}
  		if(ss==s){
  			cout<<k<<endl;
  			b = 1;
  			break;
  		}
  	}
  	if(!b) cout<<-1<<endl;
  }  
  return 0;
}