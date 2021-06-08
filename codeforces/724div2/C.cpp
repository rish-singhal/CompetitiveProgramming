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
  int t;
  cin >> t;
  while(t--){
  	int n; cin >> n;
  	string s; cin >> s;
  	map<pair<int,int>, int> mm;
  	int d =0 ,k = 0;
  	for(int i =0; i < n; i++){
  		if(s[i] == 'D'){
  			d++;
  		}
  		else{
  			k++;
  		}
  		int gg = gcd(d ,k);
  		mm[{(d/gg), (k/gg)}]++;
  		cout << mm[{(d/gg), (k/gg)}] << " ";
  	}
  	cout << endl;
  }
  return 0;
}