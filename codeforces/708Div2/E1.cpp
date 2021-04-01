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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// 6, 2, 1, 

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	int n, k; cin >> n >> k;
  	vi v(n);
  	set <LL> s;
  	LL an = 0;
  	forn(i, n) {
  		cin >> v[i];
  		int pr = 1;
  		int vv = v[i];
  		for(int j = 2; j*j <= v[i]; j++){
  			if(vv%j == 0){
  				int cnt = 0;
  				while(vv%j == 0){
  					vv/=j;
  					cnt++;
  				}
  				if(cnt%2 == 1){
  					pr *= j;
  				}
  			}
  		}
  		if(vv!=1)
  			pr *= vv;

  		if(s.find(pr)!=s.end()){
  			an++;
  			s.clear();
  			s.insert(pr);
  		}
  		else 
  			s.insert(pr);
  	}
  	cout << an + 1 << endl;
  }
  return 0;
}
