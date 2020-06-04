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

/*
	alaska
	-- alaska (1) , alaska, aksala 	
					asalka
					asklaa
	alaska, 1 2 3 4 5     1 2 3 4 5  1 2 3 4 5
			2 3 4 5 1 (2) 3 4 5 2 1	 4 5 1 2 3	 (5,3)
	
	1 2 3 4 5 6	 3 4 5 6 1 2   5 6 1 2 3 4 (6,4)
	2 3 4 5 6 1  4 5 6 3 2 1

	lfpbavjsm   
	b
	1 2 3 4
	2 1 3 4
	2 3 1 4
	2 3 4 1
*/						


int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	string s; cin>>s;
  	vector<pair<string,int>> v;
  	for1(i,n){
  		string a = s.substr(0,i-1);
  		string b = s.substr(i-1,n-(i-1));
  		//cout<<i<<" "<<a<<" "<<b<<endl;
  		if((i%2)==(n%2))
  			reverse(all(a));
  		v.pb({b+a, i});
  	}
  	sort(all(v));
  	cout<<v[0].fi<<endl;
  	cout<<v[0].se<<endl;
  }
  return 0;
}