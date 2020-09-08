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
  int n; cin>>n;
  vector<int> v(n);
  forn(i,n){
  	cin>>v[i];
  }
  set<pair<int,int>> s;
  vector<int> an;
  for(int i=n-1;i>=0;i--){
  //	cout<<s.size()<<endl;
  	if(s.size()==0) {
  		an.pb(-1);
  		s.insert({v[i],i});
  		continue;
  	}
  	auto x = s.lower_bound({v[i],-1e7});
  	if(((*x).fi>=v[i] && x==s.begin())) {
  	//	cout<<"yes"<<endl;
  		an.pb(-1);
  		if((*s.begin()).fi > v[i]) s.insert({v[i],i});
  		continue;
  	}
  	  //	cout<<(*x).fi<<" "<<(*x).se<<endl;
  	if(x==s.end() || (*x).fi>=v[i] ) x--;
  	
  	//cout<<(*x).fi<<" "<<(*x).se<<endl;
  	an.pb(((*x).se-i-1));
  	if((*s.begin()).fi > v[i]) s.insert({v[i],i});
  }
  reverse(all(an));
  for(auto i:an) cout<<i<<" ";
  	cout<<endl;
  return 0;
}