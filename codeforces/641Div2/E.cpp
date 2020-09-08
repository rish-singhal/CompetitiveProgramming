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

000    111
111 => 000 "alternate" 
000    111

01011   01000
10110   10000
01101   00
11010
10101

*/


int main(){
  fio();
  int n,m,t; cin>>n>>m>>t;
  vector<bitset<1000>> v(n);
  forn(i,n) {
  	string s; cin>>s;
  	forn(j,m)
  		v[i][j] = s[j]-'0';
  	}
  map <vector<bitset<1000> > ,int> ma;
  vector<vector<bitset<1000> > > am;
  vector<bitset<1000> > nv = v;
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  int cnt = 0;
  while(ma[nv]!=1){
  	ma[nv] = 1;
  	am.pb(nv);
  	vector <bitset<1000> > vn(n);
  	forn(i,n){
  		string q ="";
  		forn(j,m){
  			int b = 1;
  			forn(k,4){
  				int x = i+dx[k], y = j+dy[k];
  				if(x<0||x>=n||y<0||y>=m) continue;
  				b &= nv[i][j]!= nv[x][y];
  			}
  			b^=1;
  			vn[i][j] = nv[i][j]^b;
  		}
  	}
  	nv = vn;
  	++cnt;
  }

  int k =0;
  while(am[k]!=nv) k++;
  LL z = k;
  vector<vector<bitset<1000>> > xx;
  while(k<am.size()){
  	xx.pb(am[k++]);
  }
 	
  while(t--){
  	LL i, j, p;
  	cin>>i>>j>>p;

  	i--, j--;
  	if(p<z){
  		cout<<am[p][i][j]<<endl;
  		continue;
  	}
  	LL zz = (p-z)%(LL)xx.size();
  	cout<<xx[zz][i][j]<<endl;

  }
  return 0;
}