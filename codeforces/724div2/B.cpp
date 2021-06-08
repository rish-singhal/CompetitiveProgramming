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
  int t; cin>> t;
  while(t--) {
  	int n; cin >> n;
  	string s; cin >> s;
  	map <string, int> m;
  	
  	forn(i, n) {
  		m[s.substr(i, 1)] = 1;
  		if(i+1 < n){
  			m[s.substr(i, 2)] = 1;
  			if(i + 2 < n){
  				m[s.substr(i, 3)] = 1;
  			}
  		}
  	}
  	int b = 0;
  	for(int i = 0; i < 26; i++){
  		string aa = "";
  		aa+=(char)('a'+i);
  		if(m[aa] == 0){
  			cout << aa << endl;
  			b = 1;
  			break;
  		}
  	}

  	if(b) continue;
  	for(int i = 0; i < 26; i++){
  		for(int j = 0; j < 26; j++){
  			string aa = "";
  			aa+=(char)('a'+i);
  			aa+=(char)('a'+j);
  		if(m[aa] == 0){
  			cout << aa << endl;
  			b = 1;
  			break;
  		}
  	}
  	if(b) break;
  	}

  	if(b) continue;
  	for(int i = 0; i < 26; i++){
  		
  		for(int j = 0; j < 26; j++){
  			
  			for(int k  =0; k < 26; k++){
  				string aa = "";
  		aa+=(char)('a'+i);
  		aa+=(char)('a'+j);
  			aa+=(char)('a'+k);  		
  			if(m[aa] == 0){
  			cout << aa << endl;
  			b = 1;
  			break;
  		}
  		
  	}
  	if(b) break;
  	}
  	if(b) break;
  }
}
  return 0; 
}