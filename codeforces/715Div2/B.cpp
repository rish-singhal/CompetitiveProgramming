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
  	int n ; cin >> n;
  	string s; cin >> s;
  	vector <int> vv;
  	map <int, int> mm;
  	int cnt = 0;
  	int pai = 0;
  	int b = 0;
  	forn(i, n){
  		if(s[i] == 'T'){
  			vv.push_back(i);
  		}
  		else{
  			if (cnt < sz(vv)){
  				mm[vv[cnt]] = 1;
  				cnt++;
  				pai++;
  			}
  			else {
  				b = 1;
  				break;
  			}
  		}
  	}
  	int chk = (3*pai == n);
  	reverse(all(s));
  	vector <int> vv2;
  	int cnt2 = 0;
  	forn(i, n){
  		if(s[i] == 'T' && mm[n - 1 -i] == 0){
  			vv2.push_back(i);
  			// for(auto j: vv2){
  			// 	cout << j << " ";
  			// }
  			// cout << endl;
  		}
  		else if(s[i] == 'M'){
			if (cnt2 < sz(vv2)){
  				cnt2++;
  				//cout << "yes" << endl;
  				pai --;
  			}
  			else {
  				b = 1;
  				break;
  			}
  		}
  	}
  	//cout << b << endl;

  	if((!b) && pai == 0 && chk){
  		cout << "YES" << endl;
  	}
  	else {
  		cout << "NO" << endl;
  	}
  }
  return 0;
}