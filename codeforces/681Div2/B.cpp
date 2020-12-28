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

// b*m > a
// b/a > m

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	LL a, b; cin>>a>>b;
  	string s; cin>>s;
  	LL cn = 0;
  	
  	vector<LL> v[2];
  	int zc = 0;
  	while(s[zc]=='0') zc++;
  	if(zc == sz(s) ){
  		cout<<0<<endl;
  		continue;
  	}
  	int k = s[zc]-'0';
  	for(int  i = zc; i < sz(s); i++){
  		int z = s[i]-'0';
  		if(z == k){
  			cn++;
  		}
  		else{
  	//		cout<<k<<" "<<cn<<endl;
  			v[k].pb(cn);
  			k ^= 1;
  			cn = 1;
  		}
  	}
  	//cout<<k<<" "<<cn<<endl;
  	v[k].pb(cn);

	LL an = (LL)a*v[1].size();
	//cout<<v[1].size()<<endl;
	//cout<<an<<endl;
	
	//int zz = a/b;
	for(auto i: v[0]){
		if(i*b - a < 0){
			an += -a  + i*b;
		}
	}
	if(v[0].size() > 0 && sz(s) >= 1 && b*v[0][sz(v[0])-1] -a < 0 && s[sz(s)-1] == '0'){
		an -= -a  + v[0][sz(v[0])-1]*b;
	}
	cout<<an<<endl;
  }
  return 0;
}