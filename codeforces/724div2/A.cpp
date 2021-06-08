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

int main(){
  fio();
  int t; cin >> t;
  while(t--) {
   	int n;
   	cin >> n;
   	vector <int> v(n);
   	set<int> s;
   	int b = 0;
   	int gg = 0;
   	int ch =0;
   	forn(i, n){
   		cin >> v[i];
   		s.insert(v[i]);
   		if(v[i] < 0){b = 1;}
   		gg = gcd(gg, v[i]);	
   		if(!v[i]){

   			ch = 1;
   		}
   	}
   	if(b){
   		cout << "NO" << endl;
   		continue;
   	}
   	int mx = *max_element(all(v));
   	int an = (mx/gg) + ch;
   	if(an > 300) {
   		cout << "NO" << endl;
   		continue;
   	}
   	cout << "YES" << endl;
   	cout << an<< endl;
   	if(ch) cout << 0 << " ";
   	for(int i = gg; i <= mx; i+= gg){
   		cout << i << " ";
   	}
   	cout << endl;
  }
  return 0;
}
