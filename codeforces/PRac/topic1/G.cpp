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
  LL w,h,n; cin>>w>>h>>n;
  set<pair<LL,LL>> a,b;
  multiset<LL> aa,bb;
  a.insert({1,w});
  aa.insert(w);
  b.insert({1,h});
  bb.insert(h);
  while(n--){
  	string s; cin>>s;
  	LL x; cin>>x;

  	if(s=="H"){

  		auto z = b.lower_bound({x,-1e7});

  		if(z==b.end() || (*z).fi>x) z--;
  		
  		auto pp = *z;
  		  		
  		b.erase(*z);
  		LL len = pp.se-pp.fi+1;
  		//cout<<pp.fi<<" "<<pp.se<<endl;
  		b.insert({pp.fi,x});
  		b.insert({x+1,pp.se});
  		bb.erase(bb.find(len));
  		bb.insert(x-pp.fi+1);
  		bb.insert(pp.se-x);
  		cout<<((*bb.rbegin())*(*aa.rbegin()))<<endl;
  	}
  	else{
  		auto z = a.lower_bound({x,-1e7});
  		if(z==b.end() || (*z).fi>x)  z--;
  		auto pp = *z;
  		//cout<<pp.fi<<" "<<pp.se<<endl;
  		a.erase(*z);
  		LL len = pp.se-pp.fi+1;
  		//cout<<"len: "<<len<<endl;
  		a.insert({pp.fi,x});
  		a.insert({x+1,pp.se});
  		aa.erase(aa.find(len));
  		aa.insert(x-pp.fi+1);
  		aa.insert(pp.se-x);
  		cout<<((*bb.rbegin())*(*aa.rbegin()))<<endl;
  	}
  }
  return 0;
}