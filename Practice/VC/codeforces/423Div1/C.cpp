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

set<int> ss[4][10][10];

int main(){
  fio();
  string s; cin>>s;
  int n = s.size();
  map<char,int> m;
  m['A'] = 0, m['T'] = 1, m['G'] =2, m['C'] =3;
  forn(i,n){
  	int inn = i%10;
  	int nn = m[s[i]];
  	forn(j,10){
  		int kk = (inn - j + 10)%10;
  		//ss[nn][kk][inn].insert(i);
  		ss[nn][inn][kk].insert(i);
  		 //xcout<<nn<<" "<<inn<<" "<<kk<<" : "<<i<<endl;
  	}
  }
  for(auto i:ss[0][0][3])
  	cout<<i<<" ";
  cout<<endl;
  int t; cin>>t;
  while(t--){
  	int k; cin>>k;
  	if(k==1){
  		int pos; string p; cin>>pos>>p;
  		pos--;
  		int kkk = pos;
  		int nn = m[s[pos]];
  		s[pos] = (p[0]);
  		int nw = m[p[0]];
  		pos%=10;
  		forn(j,10){
  			int kk = (pos + j)%10;
  			ss[nn][pos][kk].erase(kkk);
  			ss[nw][pos][kk].insert(kkk);
  		}
  	}
  	else{
  		int l,r; string p; cin>>l>>r>>p;
  		l--,r--;

  		int an =0;
  		int ok = l%10;
  		forn(i,p.size()){
  			for(auto kk:ss[m[p[i]]][ok][i]){
  				if(kk >= l && kk<=r) an++;
  			}
  			//an += distance(ss[m[p[i]]][ok][i].upper_bound(r-1), ss[m[p[i]]][ok][i].lower_bound(l));
  		}
  		cout<<"yes"<<endl;
  		cout<<an<<endl;
  	}
  }
  return 0;
}