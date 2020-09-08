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
  vector <pair<LL,LL> > v;
  vector <pair<LL,LL> > vx, vz;
  forn(i,n){
  	LL x = 0, z = 0;
  	string s; cin>>s;
  	LL t = 0;
  	while(s[t]==')' && t<s.size()){
  		x++;
  		z-=1;
  		t++;
  	}
  	while(t<s.size()){
  		if(s[t]==')') z--;
  		else z++;
  		t++;
  	}
  	if(z==s.size()) vx.pb({x,z});
  	else if(z==-1*s.size()) vz.pb({x,z});
  	else v.pb({x,z});
  }

  LL aa = 0, bb = 0;
  for(auto i:vx){
  	aa = bb - i.fi;
  	if(aa<0){
  		cout<<"No"<<endl;
  		return 0;
  	}
  	bb+=i.se;
  }
  sort(all(v), [&](pair<LL,LL> a, pair<LL,LL> b){
  	if(a.se==b.se) return a.fi < b.fi;
    return a.se > b.se;
  });
  ///for(auto i:v) cout<<i.fi<<" "<<i.se<<endl;
  for(auto i:v){
  	aa = bb - i.fi;
  	if(aa<0){
  		cout<<"No"<<endl;
  		return 0;
  	}
  	bb+=i.se;
  }

  for(auto i:vz){
  	aa = bb - i.fi;
  	if(aa<0){
  		cout<<"No"<<endl;
  		return 0;
  	}
  	bb+=i.se;
  }

  cout<<(bb==0?"Yes":"No")<<endl;
  return 0;
}